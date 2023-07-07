#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>

void getFileValue(std::string file, int type);


class BitcoinExchange
{
    public:

        BitcoinExchange(std::string inputFile, std::string dataFile);
        BitcoinExchange(BitcoinExchange const &cpy);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
       ~BitcoinExchange(void);

        void getKeyValue(std::string line, int type);
        void getFileValue(std::string file, int type);
        void exchange(std::string key, float value) const;

    private:

        std::string _inputFile;
        std::string _dataFile;
        std::map<std::string, float> _dataMap;
        BitcoinExchange(void);
};

#endif
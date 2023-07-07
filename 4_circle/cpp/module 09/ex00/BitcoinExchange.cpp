/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:32:36 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/21 16:14:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string inputFile, std::string dataFile) : _inputFile(inputFile), _dataFile(dataFile)
{
	getFileValue(_dataFile, 2);
	getFileValue(_inputFile, 1);
   return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
    std::cout << " BitcoinExchange Constructor par copy called\n";
    *this = cpy;
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        _dataFile = rhs._dataFile;
		_inputFile = rhs._inputFile;
		_dataMap = rhs._dataMap;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "BitcoinExchange Destructor called\n";
    return ;
}

std::string withoutSpace(std::string str)
{
	std::string tmp;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			i++;
		if (i < str.length())
			tmp += str[i];
	}
	return (tmp);
}

bool isFloat(std::string str)
{
	int first = 0;
	if (str[0] == '-')
		first++;
	if (str.empty())
		return (0);
	for (size_t i = first; i < str.length(); i++)
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.')
			return (0);
	}
	return (1);
}

void BitcoinExchange::getKeyValue(std::string line, int type)
{
    std::string key;
    std::string value;
	float fValue = 0;
	int	key_i = 0;

    for (int i = 0; line[i] != ',' && line[i] != '|' && line[i] != '\n' && line[i] != '\0'; i++){
        key += line[i];
		key_i++;
	}
	key += "\0";
    for (int i = key_i + 1; line[i] != '\n' && line[i] != '\0'; i++)
            value += line[i];
	if (type == 1)
	{
		key = withoutSpace(key);
		value = withoutSpace(value);
	}
	if (!isFloat(value))
		fValue = -1;
	else
		fValue = std::stof(value);
	if (type == 1)
		exchange(key, fValue);
	if (type == 2)
		_dataMap.insert(std::pair<std::string, float>(key, fValue));

}

void BitcoinExchange::getFileValue(std::string file, int type)
{
    std::string line;

    for (int i = 0; file[i]; i++)
    {
        line += file[i];
        if (file[i] == '\n')
        {
            getKeyValue(line, type);
            line.clear();
        }
    }
}

bool valueCheck(float value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return (0);
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large number.\n";
		return (0);
	}
	return (1);
}

void getDate(std::string key, std::string &date, size_t t)
{
	for (size_t i = t; i < key.length() && key[i] != '-'; i++)
	{
		date += key[i];
	}
}

bool keyCheck(std::string key)
{
	std::string year;
	std::string month;
	std::string day;

	if (key [0] == '-')
	{
		std::cerr << "Error: negative date doesnt exist\n";
		return (0);
	}
	getDate(key, year, 0);
	getDate(key, month, year.length() + 1);
	getDate(key, day, year.length() + month.length() + 2);
	if (year.length() != 4 || year[0] != '2' || year[1] != '0')
	{
		std::cerr << "Error: that year is a bit to far from now\n";
		return (0);
	}
	if (month.length() != 2 || (month[0] < '0' || month[0] > '1'))
	{
		std::cerr << "Error: none existing month\n";
		return (0);
	}
	if ((month[0] == '0' && (month[1] < '1' || month[1] > '9')))
	{
		std::cerr << "Error: none existing month\n";
		return (0);
	}
		if ((month[0] == '1' && (month[1] < '0' || month[1] > '2')))
	{
		std::cerr << "Error: none existing month\n";
		return (0);
	}
	if (day.length() != 2 || (day[0] < '0' || day[0] > '3'))
	{
		std::cerr << "Error: none existing day\n";
		return (0);
	}
	if ((day[0] == '0' && (day[1] < '1' || day[1] > '9')))
	{
		std::cerr << "Error: none existing day\n";
		return (0);
	}
		if ((day[0] == '1' && (day[1] < '0' || day[1] > '9')))
	{
		std::cerr << "Error: none existing day\n";
		return (0);
	}
		if ((day[0] == '2' && (day[1] < '0' || day[1] > '9')))
	{
		std::cerr << "Error: none existing day\n";
		return (0);
	}
		if ((day[0] == '3' && (day[1] < '0' || day[1] > '1')))
	{
		std::cerr << "Error: none existing day\n";
		return (0);
	}
	return (1);
}

void BitcoinExchange::exchange(std::string key, float value) const
{
	float multiplier;

	std::cout << "\n" << key << " | " << value << " => ";

	if (valueCheck(value) && keyCheck(key))
	{
		try {
			multiplier = _dataMap.at(key);

			std::cout << "\e[0;32mvalue : " << value << " * " << multiplier << " = " << value * multiplier << "\e[0m\n";
		}
		catch (const std::out_of_range &e)
		{
			std::map<std::string, float>::const_iterator itlow = _dataMap.lower_bound(key);
			if (itlow == _dataMap.end()) {
				itlow = _dataMap.end();
			}
			else {
				itlow--;
				if (itlow == _dataMap.begin())
				{
					itlow++;
					std::cout << "That years was too long ago, we don't have any data before 2009, using closest one \n" << itlow->first << " ";
					std::cout << "\e[0;32mValue: " << value << " * " << multiplier << " = " << value * multiplier << "\e[0m\n";
				}
				else {
					multiplier = itlow->second;
					std::cout << "Date not in database, using closest one \n" << itlow->first << " ";
					std::cout << "\e[0;32mValue: " << value << " * " << multiplier << " = " << value * multiplier << "\e[0m\n";
				}
			}
		}
	}
}
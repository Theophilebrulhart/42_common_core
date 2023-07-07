/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:48:08 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/19 13:57:33 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int	ifs(std::string filename, std::string *tmp)
{
	std::ifstream ifs (filename.c_str(), std::ifstream::in);
	if (ifs.fail())
	{
		std::cout << "No such file found\n";
		return (0);
	}
	char c = ifs.get();
	while (ifs.good())
	{
		*tmp += c;
		c = ifs.get();
	}
	ifs.close();
	*tmp += '\n';
	return (1);
}

std::string getFileContent(std::string input)
{
   std::string tmp;
	if (input.empty())
	{
		std::cout << "Empty input\n";
		return (input);
	}
	if (!ifs(input, &tmp))
		return (tmp);
	return (tmp);
}



int main(int argc, char **argv)
{
    (void) argv;
    std::string inputFile;
    if (argc != 2)
    {
        std::cerr << "Please enter ONE and only ONE inputFile\n";
        return (1);
    }
	std::string input = argv[1];
	std::string dataFile = "data/database/data.csv";
    inputFile = getFileContent(input);
	dataFile = getFileContent(dataFile);
    if (inputFile.empty())
    {
        std::cerr << "Input file not valid\n";
        return (1);
    }
    std::cout << "\ninput file : \n " << inputFile << "\n\n";
	BitcoinExchange exchange(inputFile, dataFile);
    return (0);
}
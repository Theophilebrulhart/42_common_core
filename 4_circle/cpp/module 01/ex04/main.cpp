/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:04:59 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 17:19:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	return (1);
}

int	ofs(std::string filename, std::string tmp, std::string s1, std::string s2)
{
	std::string replaceFile = filename + ".replace";
	std::ofstream ofs (replaceFile.c_str(), std::ofstream::out);
	if (ofs.fail())
	{
		std::cout << "Sorry, we can't build your .replace file\n";
		return (0);
	}
	for (std::size_t found = tmp.find(s1); found != tmp.npos;)
	{
		tmp.erase(found, s1.length());
		tmp.insert(found, s2);
		found = tmp.find(s1);
	}
	ofs << tmp;
	ofs.close();
	return (1);
}

int	replace(std::string filename, std::string s1, std::string s2)
{
	std::string tmp;
	if (s1.empty())
	{
		std::cout << "Please give a valid string\n";
		return (0);
	}
	if (!ifs(filename, &tmp))
		return (0);
	if (!ofs(filename, tmp, s1, s2))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "please give info such as : <filename> <s1> <s2>\n";
		return (1);
	}
	std::string file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (!replace(file, s1, s2))
	{
		std::cout << "Nothing happened\n";
		return (1);
	}
	std::cout << "Done ! Go check your file ! I changed it for you :)\n";
	return (0);
}
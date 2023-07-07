/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:12:20 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/15 18:13:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>


int main(void) 
{
	std::string tmp("bite");
	std::string replaceFile = "Test/test.test";
	std::ofstream ofs (replaceFile.c_str(), std::ofstream::out);
	if (ofs.fail())
	{
		std::cout << "Sorry, we can't build your .replace file\n";
		return (0);
	}
	ofs << tmp;
	ofs.close();
	return (1);
}
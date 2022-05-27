/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:48:14 by armendes          #+#    #+#             */
/*   Updated: 2022/05/27 19:07:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

int	main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		str;
	std::size_t		found;
	std::string		replaced;
	std::string		replacer;

	if (argc != 4)
	{
		std::cerr << "You should put a filename and two strings only!" << std::endl;
		return (1);
	}
	file.open(argv[1], std::ios::in | std::ios::out);
	if (!file)
	{
		std::cerr << "The file can't be open or is a directory!" << std::endl;
		return (1);
	}

	std::string	tmp = argv[1];
	tmp += ".replace";
	char		name_of_file_replace[tmp.length() + 1];
	strcpy(name_of_file_replace, tmp.c_str());

	std::ofstream	file_replace;
	file_replace.open(name_of_file_replace, std::ios::out);

	replaced = argv[2];
	if (replaced.empty() == true)
	{
		while (!file.eof() && std::getline(file, str))
			file_replace << str << std::endl;
	}
	else
	{
		replaced = argv[2];
		replacer = argv[3];
		while (!file.eof() && std::getline(file, str))
		{
			found = 0;
			while (found != std::string::npos)
			{
				found = str.find(argv[2], 0, strlen(argv[2]));
				if (found != std::string::npos)
				{
					str.erase(found, replaced.length());
					str.insert(found, replacer);
				}
				found = str.find(argv[2], 0, strlen(argv[2]));
			}
			file_replace << str << std::endl;
		}
	}
}

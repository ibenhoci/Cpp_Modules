/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:25:11 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/18 13:08:00 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	if (argc != 1)
		return 0;
	(void)argv;

	PhoneBook phonebook;
	std::string input;
	phonebook.n = 0;
	while (1) {
		std::cout << "Enter a command: ADD-SEARCH-EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			if (phonebook.n == 8)
				phonebook.fix_list();
			if (phonebook.list[phonebook.n].fill_contact() == false) {
				std::cout << "Invalid input!" << std::endl;
				continue ;
			}
			if (phonebook.n < 8)
				phonebook.n++;
		}
		else if (input == "SEARCH") {
			if (phonebook.n != 0) {
				for (int i = 0; i < phonebook.n; i++)
					phonebook.list[i].print_info(i);
			}
			else {
				std::cout << "No contacts yet!" << std::endl;
				continue ;
			}
			std::string	str;
			std::cout << "Enter an index" << std::endl;
			std::cin >> str;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			if (str.size() != 1 || !std::isdigit(str[0]) || str[0] == '9') {
				std::cout << "Invalid index" << std::endl;
				std::cin.clear();
				continue ;
			}
			int nbr = std::stoi(str);
			if (nbr >= phonebook.n || nbr < 0) {
				std::cout << "Invalid index" << std::endl;
				std::cin.clear();
				continue ;
			}
			else
				phonebook.list[nbr].print_all();
		}
		else if (input == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Unknown command!" << std::endl;
	}
}

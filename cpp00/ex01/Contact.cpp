/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:52 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/18 12:57:03 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static bool is_numbers(std::string input) {
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.size(); i++) {
		if (isdigit(input[i]) == false)
			return false;
	}
	return true;
}

static bool is_valid(std::string input) {
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.size(); i++) {
		if (std::isalpha(input[i]) == false && input[i] != ' ') 
			return false;
	}
	bool flag = true;
	for (size_t i = 0; i < input.size(); i++) {
		if (input[i] != ' ') {
			flag = false;
			break ;
		}
	}
	if (flag == true)
		return false;
	return true;
}

bool Contact::fill_contact() {
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, f_name);
	if (is_valid(f_name) == false)
		return false;

	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, l_name);
	if (is_valid(l_name) == false)
		return false;


	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, nickname);
	if (is_valid(nickname) == false)
		return false;

	std::cout << "Enter phone number name:" << std::endl;
	std::getline(std::cin, phoneNumber);
	if (is_numbers(phoneNumber) == false)
		return false;

	std::cout << "Enter darkest secret name:" << std::endl;
	std::getline(std::cin, secret);
	if (is_valid(secret) == false)
		return false;
	return true;
}

void Contact::print_info(int index) {
	std::cout << std::setw(10) << std::right << index << "|";
	if (f_name.length() > 10)
		std::cout << std::setw(10) << std::right << (f_name.substr(0, 9) + ".") << "|";
	else
		std::cout << std::setw(10) << std::right << f_name << "|";

	if (l_name.length() > 10)
		std::cout << std::setw(10) << std::right << (l_name.substr(0, 9) + ".") << "|";
	else
		std::cout << std::setw(10) << std::right << l_name << "|";
	
	if (nickname.length() > 10)
		std::cout << std::setw(10) << std::right << (nickname.substr(0, 9) + ".") << "|" << std::endl;
	else
		std::cout << std::setw(10) << std::right << nickname <<  "|" << std::endl;
}

void Contact::print_all() {
	std::cout << "First Name: " << f_name << std::endl;
	std::cout << "Last Name: " << l_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
}


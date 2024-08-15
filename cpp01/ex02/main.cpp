/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:38:23 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/14 17:53:37 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

int main (void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &rf = str;

	std::cout << "The memory address of the string is: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR: " << ptr << std::endl;
	std::cout << "The memory address held by stringREF: " << &rf << std::endl;
	std::cout << "The value of the string is: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *ptr << std::endl;
	std::cout << "The value pointed to by stringREF: " << rf << std::endl;
}


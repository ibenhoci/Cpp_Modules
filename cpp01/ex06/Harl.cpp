/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:28:02 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/20 13:52:42 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;	
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level, std::string filter) {
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	lev, filt;

	for (lev = 0; lev < 4; lev++)
	{
		if (arr[lev] == level)
			break ;
	}
	for (filt = 0; filt < 4; filt++) {
		if (arr[filt] == filter)
			break ;
	}
	if (filt == 4)
		std::cout << "Error: Unknown filter level" << std::endl;
	if (lev >= filt) {
		switch(lev) {
			case 0:
				debug();
				break ;
			case 1:
				info();
				break ;
			case 2:
				warning();
				break ;
			case 3:
				error();
				break ;
			default:
				std::cout << "Unknown filter level" << std::endl;
				break ;
		}
	}
}

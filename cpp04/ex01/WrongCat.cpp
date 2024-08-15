/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:25:57 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:26:43 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cp;
}

WrongCat &WrongCat::operator=(const WrongCat &cp) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &cp)
		this->setType(cp.getType());
	return *this;	
}

void WrongCat::makeSound(void) const {
	std::cout << this->getType() << " WrongCat making noise" << std::endl;
}
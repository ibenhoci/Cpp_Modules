/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:22:28 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:30:54 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = cp;
}
		
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cp) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &cp)
		this->setType(cp.getType());
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << this->getType() <<" WrongAnimal making sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}
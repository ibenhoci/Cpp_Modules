/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:03:23 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:48:35 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("default") {
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Deconstructor called" << std::endl;
}

Animal::Animal(const Animal &cp) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Animal &Animal::operator=(const Animal &cp) {
	std::cout << "Assignemnt operator called" << std::endl;
	if (this != &cp) {
		this->type = cp.getType();
	}
	return *this;
}

void Animal::setType(std::string type) {
	this->type = type;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << this->getType() << " Making sound" << std::endl;
}
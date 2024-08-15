/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:02:09 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:29:54 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog constructor called" << std::endl;
	this->setType("Dog");
}

Dog::~Dog(void) {
	std::cout << "Dog deconstructor called" << std::endl;
}
	
Dog::Dog(const Dog &cp) : Animal(cp) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->setType(cp.getType());
}

Dog &Dog::operator=(const Dog &cp) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &cp)
		this->setType(cp.getType());
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << this->getType() << " Barks" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:02:02 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:20:19 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat constructor called" << std::endl;
	this->setType("Cat");
}

Cat::~Cat(void) {
	std::cout << "Cat deconstructor called" << std::endl;	
}

Cat::Cat(const Cat &cp) : Animal(cp) {
	std::cout << "Cat copy constructor called" << std::endl;	
	this->setType(cp.getType());
}

Cat &Cat::operator=(const Cat &cp) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &cp)
		this->setType(cp.getType());
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << this->getType() << " Meows" << std::endl;
}

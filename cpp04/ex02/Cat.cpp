/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:02:02 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:42:06 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat(void) {
	std::cout << "Cat deconstructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat::Cat(const Cat &cp) : Animal(cp), brain(NULL) {
	std::cout << "Cat copy constructor called" << std::endl;	
	if (this != &cp)
	{
		this->setType(cp.getType());
		if (this->brain)
			delete this->brain;
		if (cp.brain)
			this->brain = new Brain(*cp.getBrain());
	}
}

void Cat::setBrain(Brain *brain) {
	this->brain = brain;
}

Brain *Cat::getBrain(void) const {
	return this->brain;
}

Cat &Cat::operator=(const Cat &member) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &member) {
		this->setType(member.getType());
		if (this->brain)
			delete this->brain;
		if (member.brain)
			this->brain = new Brain(*member.getBrain());	
	}
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meows" << std::endl;
}

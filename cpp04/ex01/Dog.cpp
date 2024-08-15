/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:02:09 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:42:16 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog(void) {
	std::cout << "Dog deconstructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}
	
Dog::Dog(const Dog &cp) : Animal(cp), brain(NULL) {
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &cp)
	{
		this->setType(cp.getType());
		if (this->brain)
			delete this->brain;
		if (cp.brain)
			this->brain = new Brain(*cp.getBrain());	
	}
}

void Dog::setBrain(Brain *brain) {
	this->brain = brain;
}

Brain *Dog::getBrain(void) const {
	return this->brain;
}

Dog &Dog::operator=(const Dog &member) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &member) {
		this->setType(member.getType());
		if (this->brain)
			delete this->brain;
		if (member.brain)
			this->brain = new Brain(*member.getBrain());
	}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Barks" << std::endl;
}
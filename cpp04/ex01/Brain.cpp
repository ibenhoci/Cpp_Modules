/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:00 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:36:47 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain::Brain(Brain &cp) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = cp;
}

void Brain::setIdea(int ind, std::string idea) {
	if (ind < 100 && ind >= 0)
		this->ideas[ind] = idea;
	else
		std::cout << "Invalid index!" << std::endl;
}

std::string Brain::getIdea(int ind) {
	if (ind < 100 && ind >= 0)
		return this->ideas[ind];
	else
	{
		std::cout << "Invalid index!" << std::endl;
		return (NULL);
	}
}

Brain &Brain::operator=(Brain &cp) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &cp)
	{
		for (int i = 0; i < 100; i++)
			this->setIdea(i, cp.getIdea(i));
	}
	return *this;
}
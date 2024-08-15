/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:06:31 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 12:16:33 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cp) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed &Fixed::operator=(const Fixed &cp) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cp)	{
		this->fixed_point = cp.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:06:31 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/24 17:30:23 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nbr << fractional_bits);
}

Fixed::Fixed(const float flo) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(flo * (1 << fractional_bits)));
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
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
}

int Fixed::toInt(void) const {
	return getRawBits() >> fractional_bits;	
}

float Fixed::toFloat(void) const {
	float f;

	f = ((float)getRawBits()) / ((float)(1 << fractional_bits));
	return f;
}

std::ostream &operator<<(std::ostream &out, const Fixed &val) {
	out << val.toFloat();
	return (out);
}

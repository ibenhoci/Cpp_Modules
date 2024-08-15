/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:06:31 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/24 16:10:57 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
}

Fixed::Fixed(const int nbr) {
	this->setRawBits(nbr << fractional_bits);
}

Fixed::Fixed(const float flo) {
	this->setRawBits(roundf(flo * (1 << fractional_bits)));
}


Fixed::Fixed(const Fixed &cp) {
	*this = cp;
}

Fixed &Fixed::operator=(const Fixed &cp) {
	if (this != &cp)	{
		this->fixed_point = cp.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
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
////////////////////////////////OPERATORS//////////////////////////////////////
bool Fixed::operator>(const Fixed &val) const {
	if (toFloat() > val.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &val) const {
	if (toFloat() < val.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &val) const {
	if (toFloat() >= val.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &val) const {
	if (toFloat() <= val.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &val) const {
	if (toFloat() == val.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &val) const {
	if (toFloat() != val.toFloat())
		return true;
	else
		return false;
}

float Fixed::operator+(const Fixed &val) const {
	return toFloat() + val.toFloat();
}

float Fixed::operator-(const Fixed &val) const {
	return toFloat() - val.toFloat();
}

float Fixed::operator*(const Fixed &val) const {
	return toFloat() * val.toFloat();
}

float Fixed::operator/(const Fixed &val) const {
	return toFloat() / val.toFloat();
}

Fixed Fixed::operator++(void) {
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(void) {
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2) {
	if (val1.getRawBits() > val2.getRawBits())
		return val2;
	else
		return val1;
}

const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2) {
	if (val1.getRawBits() > val2.getRawBits())
		return val1;
	else
		return val2;
}

Fixed &Fixed::min(Fixed &val1, Fixed &val2) {
	if (val1.getRawBits() > val2.getRawBits())
		return val2;
	else
		return val1;
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2) {
	if (val1.getRawBits() > val2.getRawBits())
		return val1;
	else
		return val2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &val) {
	out << val.toFloat();
	return (out);
}

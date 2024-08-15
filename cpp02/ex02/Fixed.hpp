/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:05:01 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/24 16:10:45 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	fixed_point;
		const static int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float flo);
		~Fixed();
		Fixed(const Fixed &cp);
		Fixed &operator=(const Fixed &cp);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed &val) const;
		bool operator<(const Fixed &val) const;
		bool operator>=(const Fixed &val) const;
		bool operator<=(const Fixed &val) const;
		bool operator==(const Fixed &val) const;
		bool operator!=(const Fixed &val) const;

		float operator+(const Fixed &val) const;
		float operator-(const Fixed &val) const;
		float operator*(const Fixed &val) const;
		float operator/(const Fixed &val) const;
		
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);

		static const Fixed &min(const Fixed &val1, const Fixed &val2);
		static const Fixed &max(const Fixed &val1, const Fixed &val2);
		static Fixed &min(Fixed &val1, Fixed &val2);
		static Fixed &max(Fixed &val1, Fixed &val2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &val);

#endif
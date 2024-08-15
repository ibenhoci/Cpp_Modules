/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:05:01 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/24 16:09:48 by ibenhoci         ###   ########.fr       */
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
};

std::ostream &operator<<(std::ostream &out, const Fixed &val);

#endif
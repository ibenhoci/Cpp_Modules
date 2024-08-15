/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIxed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:05:01 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 12:09:13 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	fixed_point;
		const static int fractional_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &cp);
		Fixed &operator=(const Fixed &cp);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif
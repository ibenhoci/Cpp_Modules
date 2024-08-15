/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:01:45 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:20:36 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		virtual ~Dog(void);		
		Dog(const Dog &cp);

		Dog &operator=(const Dog &cp);
		virtual void makeSound(void) const;
};

#endif
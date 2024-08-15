/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:01:45 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:33:58 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog(void);
		virtual ~Dog(void);		
		Dog(const Dog &cp);
		Dog &operator=(const Dog &cp);

		void setBrain(Brain *brain);
		Brain *getBrain(void) const;
		virtual void makeSound(void) const;
};

#endif
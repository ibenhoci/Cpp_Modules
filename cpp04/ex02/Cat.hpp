/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:01:15 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:34:02 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat(void);
		virtual ~Cat(void);		
		Cat(const Cat &cp);
		Cat &operator=(const Cat &cp);

		void setBrain(Brain *brain);
		Brain *getBrain(void) const;
		virtual void makeSound(void) const;	
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:01:15 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:20:29 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		virtual ~Cat(void);		
		Cat(const Cat &cp);

		Cat &operator=(const Cat &cp);
		virtual void makeSound(void) const;	
};

#endif

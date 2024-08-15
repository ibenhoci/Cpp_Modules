/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:00:46 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:48:35 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal {
	protected:
		std::string type;
		Animal(std::string type);
		Animal();
	public:
		virtual ~Animal();
		Animal(const Animal &cp);
		virtual Animal &operator=(const Animal &cp);
		std::string getType() const;
		void setType(std::string type);

		virtual void makeSound() const = 0;
};

#endif

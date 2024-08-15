/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:39:10 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:39:11 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character(const std::string &name);
		~Character();
		Character(const Character &cp);
		Character &operator=(const Character &cp);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:12:09 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/27 12:14:24 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string name;
		int hp;
		int energy;
		int attack_damage;
	public:
		ClapTrap(std::string name);
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &cp);
		ClapTrap &operator=(const ClapTrap &cp);

		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int getHp() const;
		int getEnergy() const;
		int getAttackDamage() const;
		void setName(std::string name);
		void setAttackDamage(int ad);
		void setEnergy(int en);
		void setHp(int health);
};

std::ostream &operator<<(std::ostream &out, ClapTrap &var);

#endif
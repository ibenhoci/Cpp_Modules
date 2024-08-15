/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:10:16 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 15:23:50 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main () {
	ClapTrap ct;
	ClapTrap bob("Bob");
	ClapTrap sam("Sam");
	ClapTrap cp(bob);

	ClapTrap b;
	b = bob;

	std::cout << ct << bob << cp << b << std::endl;
	
	bob.attack("Joe");
	bob.attack("Sam");
	sam.takeDamage(bob.getAttackDamage());
	sam.beRepaired(5);
	
	std::cout << bob << sam << std::endl;

	bob.setAttackDamage(20);
	bob.setEnergy(40);
	bob.setHp(100);
	std::cout << bob << std::endl;

	bob.setAttackDamage(-5);
	bob.setEnergy(-7);
	bob.setHp(-20);
	std::cout << bob << std::endl;

	bob.attack("Sam");
	sam.takeDamage(bob.getAttackDamage());
	std::cout << bob << sam << std::endl;

	sam.beRepaired(1);
	sam.attack("bob");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:37 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 15:31:32 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHp(100);
	this->setAttackDamage(20);
	this->setEnergy(50);
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap deconstructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cp) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &cp) {
		this->setName(cp.getName());
		this->setHp(cp.getHp());
		this->setAttackDamage(cp.getAttackDamage());
		this->setEnergy(cp.getEnergy());
	}
	return *this;
}
void ScavTrap::attack(std::string const &target) {
	std::cout << "ScavTrap " << this->getName() << " attacked " << target << " and dealt " << this->getAttackDamage() << " damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode." << std::endl;
}
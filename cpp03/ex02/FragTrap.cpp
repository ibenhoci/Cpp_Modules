/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:38:50 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 15:39:35 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHp(100);
	this->setAttackDamage(30);
	this->setEnergy(100);
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap deconstructor called" << std::endl; 
}

FragTrap &FragTrap::operator=(const FragTrap &member) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &member) {
		this->setName(member.getName());
		this->setHp(member.getHp());
		this->setEnergy(member.getEnergy());
		this->setAttackDamage(member.getAttackDamage());
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->getName() << " HIGH FIVE GUYS!" << std::endl;	
}
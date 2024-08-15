/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:12:49 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 15:23:19 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(10), energy(10), attack_damage(0) {
	std::cout << "Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), attack_damage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cp) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &cp) {
		name = cp.name;
		hp = cp.hp;
		energy = cp.energy;
		attack_damage = cp.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (energy > 0 && hp > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			<< attack_damage << " points of damage!" << std::endl;
		energy--;
	}
	else if (energy <= 0)
		std::cout << "ClapTrap " << name << " has no energy left!" << std::endl;
	else if (hp <= 0)
		std::cout << "ClapTrap " << name << " has no health points left!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hp == 0) {
		std::cout << "ClapTrap " << name << " is already at 0 health points!" << std::endl;
		return ;
	}
	if (amount > (unsigned int)hp)
		hp = 0;
	else
		hp -= amount;
	std::cout << "ClapTrap " << name << " has taken " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy > 0 && hp > 0) {
		hp += amount;
		energy--;
		std::cout << "CLapTrap " << name << " has healed for " << amount << " health points" << std::endl;
	}
	else if (energy <= 0)
		std::cout << "ClapTrap " << name << " has no energy left!" << std::endl;
	else if (hp <= 0)
		std::cout << "ClapTrap " << name << " has no health points left!" << std::endl;

}

std::string ClapTrap::getName() {
	return this->name;
}

int	ClapTrap::getHp() {
	return this->hp;
}

int	ClapTrap::getEnergy() {
	return this->energy;
}

int	ClapTrap::getAttackDamage() {
	return this->attack_damage;
}

void ClapTrap::setAttackDamage(int ad) {
	if (ad > 0)
		this->attack_damage = ad;
}

void ClapTrap::setEnergy(int en) {
	if (en > 0)
		this->energy = en;
}

void ClapTrap::setHp(int health) {
	if (health > 0)
		this->hp = health;			
}

std::ostream &operator<<(std::ostream &out, ClapTrap &var) {
	out << "Name: " << var.getName() << " HP: " << var.getHp() << " AD: " << var.getAttackDamage() << " Energy: " << var.getEnergy() << std::endl;
	return (out);
}
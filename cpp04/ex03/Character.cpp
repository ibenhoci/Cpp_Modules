/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:39:06 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:39:07 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : name(name) {
	for (int i = 0; i  < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character::Character(const Character &cp) : name(cp.getName()) {
	*this = cp;
}

Character &Character::operator=(const Character &cp) {
	if (this != &cp) {
		this->name = cp.getName();
		for (int i = 0; i < 4; i++)
			this->inventory[i] = cp.inventory[i];
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			std::cout << "Character: " << this->getName() << " equiped " << m->getType() << "!" << std::endl;
			return ;
		}
	}
	std::cout << "Character: " << this->getName() << "'s inventory is full and can't equip!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
		std::cout << "Character: " << this->getName() << " just unquipped something!" << std::endl;
	}
	else
		std::cout << "Character: " << this->getName() << " can't unequip, nothing in that slot!" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx <= 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
		std::cout << "Character: " << this->getName() << " just used " << this->inventory[idx]->getType() << "!" << std::endl;
	}
	else
		std::cout << "Character: " << this->getName() << " can't use!" << std::endl;
}

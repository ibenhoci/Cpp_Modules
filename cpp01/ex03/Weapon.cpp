/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:56:44 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/20 13:17:17 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("default") {
}

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::~Weapon() {	
}

void Weapon::setType(std::string type) {
	this->type = type;
}

const std::string &Weapon::getType(void) {
	return this->type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:39:16 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:39:17 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {

}

Cure::~Cure() {

}


Cure::Cure(const Cure &cp) : AMateria("cure") {
	*this = cp;
}


Cure &Cure::operator=(const Cure &cp) {
	if (this != &cp) {
		this->type = cp.getType();
	}
	return *this;
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:38:54 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:38:58 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {

}

AMateria::AMateria() : type("") {

}

AMateria::AMateria(const AMateria &cp) {
	*this = cp;
}

AMateria::~AMateria() {

}

std::string const & AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria: \"* has no spell to fire at " << target.getName() << " *\"" << std::endl;
}

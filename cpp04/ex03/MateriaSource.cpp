/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:40:05 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:40:06 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->materias[i])
			delete this->materias[i];
}


MateriaSource::MateriaSource(const MateriaSource &cp) {
	*this = cp;
}


MateriaSource &MateriaSource::operator=(const MateriaSource &cp) {
	if (this != &cp) {
		for (int i = 0; i < 4; i++)
			this->materias[i] = cp.materias[i];
	}
	return *this;
}



AMateria* MateriaSource::getMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] && this->materias[i]->getType() == type)
			return this->materias[i];
	}
	return NULL;
}


AMateria* MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return NULL;
}


void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = m;
			std::cout << "MateriaSource: " << m->getType() << " has been learned" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource could not learn " << m->getType() << "!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:39:51 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:39:55 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "----------------------------------------" << std::endl;
	ICharacter* bob = new Character("bob");
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);
	std::cout << "----------------------------------------" << std::endl;

	me->unequip(0);
	me->unequip(3);
	std::cout << "----------------------------------------" << std::endl;

	for (int i = 0; i < 4; i++)
		me->use(i, *bob);
	

	delete bob;
	delete me;
	delete src;
	delete tmp;
	// system("leaks Materia");
	return 0;
}

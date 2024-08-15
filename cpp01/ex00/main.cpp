/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:38:23 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/20 12:45:33 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	Zombie first("Stack zombie");
	Zombie *second = newZombie("Heap zombie");

	first.announce();
	second->announce();
	delete second;
	return 0;
}


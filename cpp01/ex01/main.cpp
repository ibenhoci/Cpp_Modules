/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:38:23 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/20 13:03:38 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	Zombie *horde;
	int		n;

	n = 5;
	horde = zombieHorde(n, "Randoms");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
	return  0;
}


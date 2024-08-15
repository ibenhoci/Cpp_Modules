/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:38 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 15:29:06 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:	
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cp);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &cp);
		void attack(std::string const &target);
		void guardGate(void);
};

#endif
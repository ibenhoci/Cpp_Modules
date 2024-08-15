/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:39:24 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:39:25 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure &cp);
		Cure &operator=(const Cure &cp);
		virtual AMateria*   clone() const;
		virtual void use(ICharacter &target);
};

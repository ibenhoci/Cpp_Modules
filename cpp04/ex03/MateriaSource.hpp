/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:40:09 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/29 13:40:10 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
        AMateria* materias[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &cp);
        MateriaSource &operator=(const MateriaSource &cp);

        AMateria* getMateria(const std::string &type);
        AMateria* createMateria(const std::string &type);
        void learnMateria(AMateria* m);
};

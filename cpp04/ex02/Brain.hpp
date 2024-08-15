/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:34:44 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:36:36 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain &cp);
		Brain &operator=(Brain &member);

		void setIdea(int ind, std::string idea);
		std::string getIdea(int ind);
};

#endif

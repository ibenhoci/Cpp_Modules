/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:26:38 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/20 13:53:32 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl complaint;

	if (argc == 2)
	{
		complaint.complain("DEBUG", std::string(argv[1]));
		complaint.complain("INFO", std::string(argv[1]));
		complaint.complain("WARNING", std::string(argv[1]));
		complaint.complain("ERROR", std::string(argv[1]));
	}
	else
		std::cout << "No filter level" << std::endl;
	return (0);
}

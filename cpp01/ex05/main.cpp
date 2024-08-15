/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:26:38 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/14 18:52:54 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl complaint;

	complaint.complain("DEBUG");
	complaint.complain("INFO");
	complaint.complain("WARNING");
	complaint.complain("ERROR");
	complaint.complain("dvjskdfd");
	return (0);
}

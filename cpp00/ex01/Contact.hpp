/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:46:55 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/14 16:20:36 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	public:
		std::string f_name;
		std::string l_name;
		std::string	nickname;
		std::string phoneNumber;
		std::string secret;
		bool fill_contact();
		void print_info(int index);
		void print_all();
};

#endif

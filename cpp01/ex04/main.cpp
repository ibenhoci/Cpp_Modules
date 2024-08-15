/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:14:00 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/20 13:28:29 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	sed(char **argv) {
	std::string file_name = std::string(argv[1]);
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	std::string str;
	std::ifstream infile(file_name);

	if (!infile) {
		std::cout << "Error: Cannot open file: " << file_name << std::endl;
		return ;
	}
	std::ofstream outfile(file_name + ".replace");
	if (!outfile) {
		infile.close();
		std::cout << "Error: Cannot open file: " << file_name  + ".replace" << std::endl;
		return ;
	}
	while (std::getline(infile, str)) {
		if (!s1.empty()) {
			size_t curr;
			size_t start = 0;
			while ((curr = str.find(s1, start)) != std::string::npos) {
				outfile << str.substr(start, curr - start) << s2;
				start = curr + s1.length();
			}
			outfile << str.substr(start) << std::endl;
		}
		else
			outfile << str << std::endl;
	}
	infile.close();
	outfile.close();
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid parameters" << std::endl;
		return 0;
	}
	sed(argv);
}

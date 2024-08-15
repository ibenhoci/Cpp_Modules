/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:00:29 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:29:12 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
	
int main() {
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nType is: " << dog->getType() << std::endl;
	std::cout << "Type is: " << cat->getType() << "\n" << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
	std::cout << std::endl;
	
	const WrongAnimal* wcat = new WrongCat();
	std::cout << wcat->getType() << std::endl;
	wcat->makeSound();
	std::cout << std::endl;
	
	WrongAnimal wanimal;
	std::cout << wanimal.getType() << std::endl;
	wanimal.makeSound();
	std::cout << std::endl;
	
	delete wcat;
	return (0);
}

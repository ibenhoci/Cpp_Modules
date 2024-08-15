/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:00:29 by ibenhoci          #+#    #+#             */
/*   Updated: 2024/03/15 16:51:25 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
	
int main() {
	const Animal* dog = new Dog();
	std::cout << std::endl;
   const Animal* cat = new Cat();
	std::cout << std::endl;

   delete dog;
	std::cout << std::endl;
   delete cat;
	std::cout << std::endl;

	// NONE OF THESE SHOULD WORK SINCE NOW ANIMAL IS AN ABSTRACT CLASS
	// Animal an;
	// Animal an = new animal();
	// Animal a = new Animal("animal");
	// Animal a("Ani");

   std::cout << "/////////////////////////////////////////////////////////////" << std::endl;
   {
		Dog dog;
    	std::cout << std::endl;
	   Dog dog1;
		dog1 = dog;
		std::cout << std::endl;
		Dog dog2(dog);
		std::cout << std::endl;
		std::cout << "Original: " << dog.getBrain() << std::endl;
		std::cout << "Copy: " << dog2.getBrain() << std::endl;
		std::cout << "Assignment: " << dog1.getBrain() << std::endl;
		std::cout << std::endl;

		dog.getBrain()->setIdea(0, "Hello");
		dog.getBrain()->setIdea(-1, "hi");
		dog.getBrain()->setIdea(101, "hi");
	}
	std::cout << "/////////////////////////////////////////////////////////////" << std::endl;

   const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
   std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
      delete animals[i];
		std::cout << std::endl;
	}
   return 0;
}

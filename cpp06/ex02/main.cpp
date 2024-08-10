#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base *generate(void) {
	int					n;
	std::random_device 	rd;

	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(1, 3);
	n = distribution(gen);
	switch(n) {
		case 1:
			std::cout << "Generating A" << std::endl;
			return (new A());
		case 2:
			std::cout << "Generating B" << std::endl;
			return (new B());
		case 3:
			std::cout << "Generating C" << std::endl;
			return (new C());
		default:
			std::cout << "Failed to generate an object!" << std::endl;
			return (NULL);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Failed to identify pointer type" << std::endl;
}

void identify(Base& p) {
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}	
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {
        std::cout << "Failed to identify reference type" << std::endl;
	}
}

int	main(void) {
	Base *random;

	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;
	
	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;

	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;

	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;

	Base	rnd;
	identify(&rnd);
	identify(rnd);
}
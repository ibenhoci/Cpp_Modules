# pragma once

# include <iostream>
# include <stdint.h>

typedef struct Data {
	int			nbr;
	Data		*next;
}	Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &element);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

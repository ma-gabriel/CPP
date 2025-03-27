#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>
# include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const &);
		virtual ~Serializer() = 0;
		Serializer &operator=(const Serializer &);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
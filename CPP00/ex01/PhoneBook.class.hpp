
#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

class PhoneBook {

	private:
		Contact contacts[8];
		uint64_t index;
		void print_str(std::string);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void search(void);
		void add(void);

};

#endif

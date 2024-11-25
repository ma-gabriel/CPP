
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {

	private:
		Contact contacts[8];
		short index;
		void print_str(std::string);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void search(void);
		void add(void);

};

#endif

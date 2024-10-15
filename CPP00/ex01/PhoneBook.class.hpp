
#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
# include "using_std.hpp"

class PhoneBook {

	private:
		Contact contacts[8];
		uint64_t index;
		void print_str(string);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void search(void);
		void add(void);

};

#endif

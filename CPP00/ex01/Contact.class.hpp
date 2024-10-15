
#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "using_std.hpp"

class Contact {
	public:
		string first_name;
		string last_name;
		string nickname;
		string phone_number;
		string darkest_secret;

		Contact(string first_name,
				string last_name,
				string nickname,
				string phone_number,
				string darkest_secret);
		Contact(void);
		~Contact(void);
		void show(void);

};

#endif

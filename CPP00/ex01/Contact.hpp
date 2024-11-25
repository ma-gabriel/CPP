
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mNickname;
		std::string mPhoneNumber;
		std::string mDarkestSecret;
	public:
		Contact(std::string first_name,
				std::string last_name,
				std::string nickname,
				std::string phone_number,
				std::string darkest_secret);
		Contact(void);
		~Contact(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		void show(void);

};

#endif

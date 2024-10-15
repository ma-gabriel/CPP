
#include "Contact.class.hpp"


Contact::Contact(string first_name, 
				 string last_name,
				 string nickname,
				 string phone_number, 
				 string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::Contact(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}
void Contact::show(void)
{
	cout << "first name: " << first_name << endl;
	cout << "last name: " << last_name << endl;
	cout << "nickname: " << nickname << endl;
	cout << "phone number: " << phone_number << endl;
	cout << "darkest secret: " << darkest_secret << endl;
}

Contact::~Contact(void){}

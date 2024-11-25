
#include "Contact.hpp"


Contact::Contact(std::string first_name, 
				 std::string last_name,
				 std::string nickname,
				 std::string phone_number, 
				 std::string darkest_secret)
{
	this->mFirstName = first_name;
	this->mLastName = last_name;
	this->mNickname = nickname;
	this->mPhoneNumber = phone_number;
	this->mDarkestSecret = darkest_secret;
}

Contact::Contact(void)
{
	this->mFirstName = "";
	this->mLastName = "";
	this->mNickname = "";
	this->mPhoneNumber = "";
	this->mDarkestSecret = "";
}
void Contact::show(void)
{
	std::cout << "first name: " << this->mFirstName << std::endl;
	std::cout << "last name: " << this->mLastName << std::endl;
	std::cout << "nickname: " << this->mNickname << std::endl;
	std::cout << "phone number: " << this->mPhoneNumber << std::endl;
	std::cout << "darkest secret: " << this->mDarkestSecret << std::endl;
}

Contact::~Contact(void){}

std::string Contact::getFirstName(void){
	return this->mFirstName;
}

std::string Contact::getLastName(void){
	return this->mLastName;
}

std::string Contact::getNickname(void){
	return this->mNickname;
}

// includes
#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>


// constructor
PhoneBook::PhoneBook(void){
	this->index = 0;
}

// destructor
PhoneBook::~PhoneBook(void){}

static Contact createContact(const std::string entries[5]) {
    return Contact(entries[0], entries[1], entries[2], entries[3], entries[4]);
}

void PhoneBook::add(void){
	std::string entries[5];
	const std::string prompts[5] = {"first name", "last name",
		"nickname", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i++){
		std::cout << prompts[i] << ": ";
		std::getline(std::cin, entries[i]);
		if (entries[i].length() == 0){
			std::cout << "Can't have empty field\n";
			return ;
		}
	}
	this->contacts[index % 8] = createContact (entries);
	this->index++;
}

void PhoneBook::print_str(std::string str){
	if (str.length() <= 10){
		std::cout << std::setw(10) << str;
	} else {
		std::cout << str.substr(0, 9) << '.' ;
	}
}

void PhoneBook::search(void){
	int i;
	std::cout << "       ID |first name| last name|  nickname\n";
	for (i = 0; i < this->index && i < 8; i++){
		std::cout << std::setw(10) << i << '|';
		this->print_str(this->contacts[i].first_name);
		std::cout << '|';
		this->print_str(this->contacts[i].last_name);
		std::cout << '|';
		this->print_str(this->contacts[i].nickname);
		std::cout << std::endl;
	}
	std::string str;
	std::cout << "id :";
	getline(std::cin, str);
	if (str.length() != 1 || str[0] < '0' || str[0] >= '0' + i)
		return ;
	this->contacts[str[0] - '0'].show();
}

// includes
#include "PhoneBook.class.hpp"


// constructor
PhoneBook::PhoneBook(void){
	this->index = 0;
}

// destructor
PhoneBook::~PhoneBook(void){}

static Contact createContact(const string entries[5]) {
    return Contact(entries[0], entries[1], entries[2], entries[3], entries[4]);
}

void PhoneBook::add(void){
	string entries[5];
	const string prompts[5] = {"first name", "last name",
		"nickname", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i++){
		cout << prompts[i] << ": ";
		getline(cin, entries[i]);
		if (entries[i].length() == 0){
			cout << "Can't have empty field\n";
			return ;
		}
	}
	this->contacts[index % 8] = createContact (entries);
	this->index++;
}

void PhoneBook::print_str(string str){
	if (str.length() <= 10){
		cout << setw(10) << str;
	} else {
		cout << str.substr(0, 9) << '.' ;
	}
}

void PhoneBook::search(void){
	int i;
	cout << "       ID |first name| last name|  nickname\n";
	for (i = 0; i < this->index && i < 8; i++){
		cout << setw(10) << i << '|';
		this->print_str(this->contacts[i].first_name);
		cout << '|';
		this->print_str(this->contacts[i].last_name);
		cout << '|';
		this->print_str(this->contacts[i].nickname);
		cout << endl;
	}
	string str;
	cout << "id :";
	getline(cin, str);
	if (str.length() != 1 || str[0] < '0' || str[0] >= '0' + i)
		return ;
	this->contacts[str[0] - '0'].show();
}

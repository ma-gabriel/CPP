
#include "using_std.hpp"
#include "PhoneBook.class.hpp"

int main()
{
	PhoneBook phonebook;
	string line;
	while (getline(cin, line)){
		if (line == "ADD")
			phonebook.add();
		if (line == "SEARCH")
			phonebook.search();
		if (line == "EXIT")
			break ;
		cout << "____________________________________________\n\n";
	}
	return (0);
}
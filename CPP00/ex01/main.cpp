

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string line;
	while (std::getline(std::cin, line)){
		if (line == "ADD")
			phonebook.add();
		if (line == "SEARCH")
			phonebook.search();
		if (line == "EXIT")
			break ;
		std::cout << "____________________________________________\n\n";
	}
	return (0);
}

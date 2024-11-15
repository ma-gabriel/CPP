
#include "Harl.hpp"

Harl::~Harl(){}
Harl::Harl(){}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
				 "ketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put "
				 "enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for "
				 "years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}


void Harl::complain(const std::string level)
{
	std::string breakpoints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4 and breakpoints[i] != level; i++);
	switch (i) {
		case 0:
			this->debug();
			//Intentional fallthrough
		case 1:
			this->info();
			//Intentional fallthrough
		case 2:
			this->warning();
			//Intentional fallthrough
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
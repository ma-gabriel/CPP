
#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>

__attribute__((constructor))
static void randomizeRobotomyRequest() {
	timeval tmp;
	gettimeofday(&tmp, NULL);
    std::srand(tmp.tv_usec);
}

Base *generate(void)
{
    switch (std::rand() % 3) {
        case 0:
			return new A();
        case 1:
			return new B();
        default:
			return new C();
    }
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "concrete class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "concrete class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "concrete class C" << std::endl;
	else
		std::cout << "unknown concrete class" << std::endl;
}

void identify(Base& p)
{
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "concrete class A" << std::endl;
	} catch (...){}
	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "concrete class B" << std::endl;
	} catch (...) {}
	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "concrete class C" << std::endl;
	} catch (...) {}
}
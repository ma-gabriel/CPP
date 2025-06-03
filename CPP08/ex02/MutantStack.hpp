
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iterator>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack &ref) {this->c = ref.c;}
		~MutantStack() {};
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack &operator=(const MutantStack &ref) {this->c = ref.c;};
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};
};

#endif
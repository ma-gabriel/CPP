
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
		MutantStack &operator=(const MutantStack &ref) {this->c = ref.c;};
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};
		iterator begin() const {return this->c.begin();};
		iterator end() const {return this->c.end();};
		reverse_iterator rbegin() {return this->c.rbegin();};
		reverse_iterator rend() {return this->c.rend();};
		reverse_iterator rbegin() const {return this->c.rbegin();};
		reverse_iterator rend() const {return this->c.rend();};
};

#endif
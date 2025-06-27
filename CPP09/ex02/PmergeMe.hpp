#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <string>


std::vector<int> vector_create(char **arg);
std::vector<int> vector_sort(std::vector<int> vec);
std::string vector_toString(std::vector<int> &vec);


std::deque<int> deque_create(char **arg);
std::deque<int> deque_sort(std::deque<int> vec);
std::string deque_toString(std::deque<int> &vec);

#endif
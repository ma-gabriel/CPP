#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <string>


std::vector<int> vector_create(char *arg);
std::vector<int> vector_sort(std::vector<int> vec);
std::string vector_toString(std::vector<int> &vec);
#endif
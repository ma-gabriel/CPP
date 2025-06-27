

#include "PmergeMe.hpp"

#include <string>
#include <vector>
#include <iostream> // for std::cout
#include <sstream>
#include <utility> // for std::pair

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


std::vector<int> vector_create(char **arg)
{
    std::vector<int> res;

    for (size_t i = 0; arg[i]; i++){
        std::stringstream s((std::string(arg[i])));
        while (s){
            int buff = -1;
            s >> buff;
            if (buff != -1)
                res.push_back(buff);
        }
    }
    return res;
}

static int Jacobsthal(int count)
{
    long a = 2, b = 1;
    for (int i = 0; i < count; i++){
        a *= 2;
        b *= -1;
    }
    return (a + b) / 3;
}


static void vector_sort_algo(std::vector<int> &vec, size_t size=1)
{
    if (size >= vec.size()) {
#ifdef DEBUG
        std::cout << ":" << vector_toString(vec) << "\n";
#endif
        return;
    }
    std::vector<int> A;
    std::vector<int>left;
    size_t i;
    for (i = 0; i  + size * 2 < vec.size(); i += size * 2){
        if (vec[i + size - 1] < vec[i + size * 2 - 1]){
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + j]);
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + size + j]);
        }
        else {
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + size + j]);
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + j]);
        }
    }
    for (;i < vec.size(); i++)
        left.push_back(vec[i]);
#ifdef DEBUG
    std::cout << ":" << vector_toString(A) << vector_toString(left) << "\n";
#endif
    vector_sort_algo(A, size * 2);

    std::vector<int> res;
    std::vector< std::pair<std::vector<int>, int> > small;
    std::vector< std::pair<std::vector<int>, int> > big;

    for (i = 0; i  + size * 2 < vec.size(); i += size * 2){
        std::pair<std::vector<int>, int> tmp;
        tmp.second = i / size / 2;
        for (size_t j = 0; j < size; j ++)
            tmp.first.push_back(A[i + j]);
        small.push_back(tmp);
        tmp.first.clear();
        tmp.second = -(i / size / 2) - 1;
        for (size_t j = 0; j < size; j ++)
            tmp.first.push_back(A[i + size + j]);
        big.push_back(tmp);
    }
    while (!left.empty()){
        std::pair<std::vector<int>, int> tmp;
        tmp.second = i / size / 2;
        for (size_t j = 0; j < size; j ++){
            tmp.first.push_back(left[0]);
            left.erase(left.begin());
        }
        small.push_back(tmp);
        i += size * 2;
    }

#ifdef DEBUG
        std::cout << "big:";

        for (std::vector<std::pair<std::vector<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
            std::cout << "{" << vector_toString(it->first) << " }" << ":" << it->second << " ";
        // for (std::vector<std::pair<std::vector<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
        //    std::cout << vector_toString(it->first);
        std::cout << "\nsmall:";
        for (std::vector<std::pair<std::vector<int>, int> >::iterator it = small.begin(); it != small.end(); it++)
            std::cout << "{" << vector_toString(it->first) << "}" << ":" << it->second << " ";
        std::cout << "\n";
#endif

    if (small.size()){
        big.insert(big.begin(), *small.begin());
        small.erase(small.begin());
    }

    int count = 2;
    while (small.size())
    {
        int index = Jacobsthal(count);
        std::vector<std::pair<std::vector<int>, int> >::iterator small_it;
        for (small_it = small.begin(); small_it != small.end(); small_it++){
            if (small_it->second >= index - 1)
                break;
        }
        if (small_it == small.end() || small_it->second > index - 1)
            small_it--;

        size_t big_index;
        for (big_index = 0; big_index < big.size(); big_index++){
            if (big[big_index].second < 0 && big[big_index].second < -index)
                break;
        }
        if (big_index == big.size() || 
            (big[big_index].second < 0 && big[big_index].second > index - 1))
            big_index--;

        size_t first = 0;
        size_t last = big_index + 1;
        while (first < last) {
            size_t mid = (first + last) / 2;
            if (big[mid].first[size - 1] < small_it->first[size - 1])
                first = mid + 1;
            else
                last = mid;
        }

        big.insert(big.begin() + first, *small_it);
        small.erase(small_it);


#ifdef DEBUG
        std::cout << "big:";

        for (std::vector<std::pair<std::vector<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
            std::cout << "{" << vector_toString(it->first) << " }" << ":" << it->second << " ";
        // for (std::vector<std::pair<std::vector<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
        //    std::cout << vector_toString(it->first);
        std::cout << "\nsmall:";
        for (std::vector<std::pair<std::vector<int>, int> >::iterator it = small.begin(); it != small.end(); it++)
            std::cout << "{" << vector_toString(it->first) << "}" << ":" << it->second << " ";
        std::cout << "\n";
#endif

        if (small.size() && small[0].second > index - 1)
            count++;
    }

    vec.clear();
    for (std::vector<std::pair<std::vector<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
        vec.insert(vec.end(), it->first.begin(), it->first.end());

#ifdef DEBUG
    std::cout << "vec =" << vector_toString(vec) << "\n";
#endif
}


std::vector<int> vector_sort(std::vector<int> vec) {
    vector_sort_algo(vec);
    return vec;
}


std::string vector_toString(std::vector<int> &vec)
{
    std::string str;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        str += SSTR(" " << *it);
    return str;
}



#include <deque>

std::deque<int> deque_create(char **arg)
{
    std::deque<int> res;

    for (size_t i = 0; arg[i]; i++){
        std::stringstream s((std::string(arg[i])));
        while (s){
            int buff = -1;
            s >> buff;
            if (buff != -1)
                res.push_back(buff);
        }
    }
    return res;
}

static void deque_sort_algo(std::deque<int> &vec, size_t size=1)
{
    if (size >= vec.size()) {
#ifdef DEBUG
        std::cout << ":" << deque_toString(vec) << "\n";
#endif
        return;
    }
    std::deque<int> A;
    std::deque<int>left;
    size_t i;
    for (i = 0; i  + size * 2 < vec.size(); i += size * 2){
        if (vec[i + size - 1] < vec[i + size * 2 - 1]){
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + j]);
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + size + j]);
        }
        else {
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + size + j]);
            for (size_t j = 0; j < size; j++)
                A.push_back(vec[i + j]);
        }
    }
    for (;i < vec.size(); i++)
        left.push_back(vec[i]);
#ifdef DEBUG
    std::cout << ":" << deque_toString(A) << deque_toString(left) << "\n";
#endif
    deque_sort_algo(A, size * 2);

    std::deque<int> res;
    std::deque< std::pair<std::deque<int>, int> > small;
    std::deque< std::pair<std::deque<int>, int> > big;

    for (i = 0; i  + size * 2 < vec.size(); i += size * 2){
        std::pair<std::deque<int>, int> tmp;
        tmp.second = i / size / 2;
        for (size_t j = 0; j < size; j ++)
            tmp.first.push_back(A[i + j]);
        small.push_back(tmp);
        tmp.first.clear();
        tmp.second = -(i / size / 2) - 1;
        for (size_t j = 0; j < size; j ++)
            tmp.first.push_back(A[i + size + j]);
        big.push_back(tmp);
    }
    while (!left.empty()){
        std::pair<std::deque<int>, int> tmp;
        tmp.second = i / size / 2;
        for (size_t j = 0; j < size; j ++){
            tmp.first.push_back(left[0]);
            left.erase(left.begin());
        }
        small.push_back(tmp);
        i += size * 2;
    }

#ifdef DEBUG
        std::cout << "big:";

        for (std::deque<std::pair<std::deque<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
            std::cout << "{" << deque_toString(it->first) << " }" << ":" << it->second << " ";
        // for (std::deque<std::pair<std::deque<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
        //    std::cout << deque_toString(it->first);
        std::cout << "\nsmall:";
        for (std::deque<std::pair<std::deque<int>, int> >::iterator it = small.begin(); it != small.end(); it++)
            std::cout << "{" << deque_toString(it->first) << "}" << ":" << it->second << " ";
        std::cout << "\n";
#endif

    if (small.size()){
        big.insert(big.begin(), *small.begin());
        small.erase(small.begin());
    }

    int count = 2;
    while (small.size())
    {
        int index = Jacobsthal(count);
        std::deque<std::pair<std::deque<int>, int> >::iterator small_it;
        for (small_it = small.begin(); small_it != small.end(); small_it++){
            if (small_it->second >= index - 1)
                break;
        }
        if (small_it == small.end() || small_it->second > index - 1)
            small_it--;

        size_t big_index;
        for (big_index = 0; big_index < big.size(); big_index++){
            if (big[big_index].second < 0 && big[big_index].second < -index)
                break;
        }
        if (big_index == big.size() || 
            (big[big_index].second < 0 && big[big_index].second > index - 1))
            big_index--;

        size_t first = 0;
        size_t last = big_index + 1;
        while (first < last) {
            size_t mid = (first + last) / 2;
            if (big[mid].first[size - 1] < small_it->first[size - 1])
                first = mid + 1;
            else
                last = mid;
        }

        big.insert(big.begin() + first, *small_it);
        small.erase(small_it);


#ifdef DEBUG
        std::cout << "big:";

        for (std::deque<std::pair<std::deque<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
            std::cout << "{" << deque_toString(it->first) << " }" << ":" << it->second << " ";
        // for (std::deque<std::pair<std::deque<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
        //    std::cout << deque_toString(it->first);
        std::cout << "\nsmall:";
        for (std::deque<std::pair<std::deque<int>, int> >::iterator it = small.begin(); it != small.end(); it++)
            std::cout << "{" << deque_toString(it->first) << "}" << ":" << it->second << " ";
        std::cout << "\n";
#endif

        if (small.size() && small[0].second > index - 1)
            count++;
    }

    vec.clear();
    for (std::deque<std::pair<std::deque<int>, int> >::iterator it = big.begin(); it != big.end(); it++)
        vec.insert(vec.end(), it->first.begin(), it->first.end());

#ifdef DEBUG
    std::cout << "vec =" << deque_toString(vec) << "\n";
#endif
}


std::deque<int> deque_sort(std::deque<int> vec) {
    deque_sort_algo(vec);
    return vec;
}


std::string deque_toString(std::deque<int> &vec)
{
    std::string str;
    for (std::deque<int>::iterator it = vec.begin(); it != vec.end(); it++)
        str += SSTR(" " << *it);
    return str;
}

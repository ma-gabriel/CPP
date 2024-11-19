
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); j++)
            std::cout << (char) (str[j] ^ ((str[j] >= 'a' && str[j] <= 'z') << 5));
    }
    std::cout << '\n';
    return (0);
}

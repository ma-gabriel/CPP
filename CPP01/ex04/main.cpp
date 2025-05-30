
#include <iostream>
#include <fstream>

static std::string &replace(std::string &str, const std::string s1, const std::string s2)
{
    if (s1.length() == 0){
        std::cerr << "replace: cannot treat an empty string as first arg (file unchanged)" << std::endl;
        return str;
    }

    size_t i = str.find(s1);

    while (i != std::string::npos){
        str = str.substr(0, i) + s2 + str.substr(i + s1.length(), str.length());
        i += s2.length();
        i = str.find(s1, i);
    }
    return (str);
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "please use \"./ex04 file s1 s2\"\n";
        return (1);
    }

    std::ifstream infile(argv[1]);
    if (not infile.is_open()) {
        std::cerr << "The file can't be opened\n";
        return (1);
    }

    std::ofstream outfile ((std::string (argv[1]) + ".replace").c_str());
    if (not outfile.is_open()) {
        std::cerr << "The outfile can't be created/opened\n";
        return (1);
    }

    std::string res((std::istreambuf_iterator<char>(infile)),
                       std::istreambuf_iterator<char>());
    // std::string res;
    // while (infile)
    // {
    //     std::string tmp;
    //     std::getline(infile, tmp);
    //     res += tmp;
    //     if (infile)
    //         res += "e";
    // }
    infile.close();

    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    replace(res, s1, s2);

    outfile << res;
    outfile.close();
}
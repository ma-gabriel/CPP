
#include <iostream>
#include <fstream>

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

    std::ofstream outfile ((std::string) argv[1] + (std::string)".replace");
    if (not outfile.is_open()) {
        std::cerr << "The outfile can't be created/opened\n";
        return (1);
    }

    std::string res;
    getline(infile, res, '\0');
    infile.close();

    std::string s1 = argv[2];
    std::string s2 = argv[3];
    for (int i = 0; i <= res.length(); i++){
        if (res.substr(i, s1.length()) == s1){
            res = res.substr(0, i) + s2 + res.substr(i + s1.length(), res.length());
            i += s2.length() - s1.length();
        }
    }

    outfile << res;
}
#ifndef BITCOINEXCHANGE_CPP
# define BITCOINEXCHANGE_CPP
# include <map>
# include <string>

class BitcoinExchange
{
    public:
        void process(char *);
        BitcoinExchange();
        ~BitcoinExchange();
    private:
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);

        std::map<std::string, double> _data;
        bool isValidNumber(const std::string& s, double& result, bool check = true);
        bool isValidDate(const std::string& date);
};

#endif
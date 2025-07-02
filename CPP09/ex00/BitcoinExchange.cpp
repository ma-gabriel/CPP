
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>
#include "BitcoinExchange.hpp"

#define NB_DAYS  (int[12]){31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

#define ISLEAPYEAR(year) (!(year % 4))

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &){}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &){return *this;}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream in("data.csv");
    if (!in) throw ("Can't open data.csv");

    std::string line;
    if (!std::getline(in, line) || line != "date,exchange_rate")
        throw "invalid header";

    while (std::getline(in, line)) {
        std::string::size_type sep = line.find(',');
        if (sep == std::string::npos)
            throw "Invalid format in data.csv";

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);

        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        if (!isValidDate(date))
            throw "Invalid date in data.csv";

        double value;
        if (!isValidNumber(valueStr, value, false))
            throw "Invalid value in data.csv";
        _data[date] = value;
    }
}


bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
    int year, month, day;
    std::istringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-') return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > NB_DAYS[month - 1] + (ISLEAPYEAR(year) * (month == 2))) return false;
    return true;
}

bool BitcoinExchange::isValidNumber(const std::string& s, double& result, bool check) {
    char* endptr;
    result = std::strtod(s.c_str(), &endptr);
    if (*endptr != '\0') return false;
    if (check && (result > 1000. || result < 0.)) return false;
    return true;
}


void BitcoinExchange::process(char *file)
{
    std::ifstream in(file);
    if (!in) throw "Can't open the file";

    std::string line;
    if (!std::getline(in, line) || line != "date | value")
        throw "invalid header";

    while (std::getline(in, line)) {
        std::string::size_type sep = line.find('|');
        if (sep == std::string::npos){
            std::cerr << "invalid format, missing pipe : " << line << std::endl;
            continue; 
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);

        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        if (!isValidDate(date)){
            std::cerr << "Invalid date: " << date << std::endl;
            continue;
        }

        double value;
        if (!isValidNumber(valueStr, value)){
            std::cerr << "Invalid value: " << valueStr << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator prev = _data.begin();
        if (date < prev->first){
            std::cerr << date << " not yet in the sheet" << std::endl;
            continue;
        }
        for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++){
            if (it->first == date){
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;  
                break;
            }
            else if (it->first > date){
                std::cout << date << " => " << value << " = " << value * prev->second << std::endl; 
                break;
            }
            else
                prev = it;
        }
    }


}
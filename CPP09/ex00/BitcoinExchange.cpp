#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open db file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        
        std::istringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
        {
            std::cerr << "Error: bad line format in db => " << line << std::endl;
            continue;
        }

        date = trim(date);
        rateStr = trim(rateStr);

        if (!isValidDate(date))
        {
            std::cerr << "Error: Invalid date in db =>" << line << std::endl;
            continue;
        }

        float rate = std::atof(rateStr.c_str());
        if (rate < 0)
        {
            std::cerr << "Error: negative rate in db => " << line << std::endl;
            continue;
        }
        exchangeRates[date] = rate;
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::istringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad date => " << date << std::endl;
            continue;
        }

        float value = std::atof(valueStr.c_str());
        if (!isValidValue(value))
        {
            std::cerr << "Error: invalid value => " << value << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.end())
        it--;
    else if (it->first != date)
    {
        if (it == exchangeRates.begin())
            return 0;
        it--;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

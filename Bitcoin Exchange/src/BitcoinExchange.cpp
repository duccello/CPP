#include "BitcoinExchange.hpp"

//canon: 
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->data = other.data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

//methods:
void    BitcoinExchange::loadData()
{
    std::ifstream dataFile("data.csv");
    if (dataFile.is_open()) 
    {
        std::string line;
        while (std::getline(dataFile, line))
        {   
            if (line == "date,exchange_rate")
                continue;
            size_t comaPos = line.find(",");
            if (comaPos == std::string::npos)
                throw std::runtime_error("Error in data file: no separator");
            std::string date = line.substr(0, comaPos);
            if (date.empty() || dateValid(date) == false)
                throw std::runtime_error("Error in data file: date");
            std::string value = line.substr(comaPos + 1);
            if (value.empty())
                throw std::runtime_error("Error in data file: value");
            std::istringstream iss(value);
            double num;
            if (iss >> num)
                data[date] = num;
            else
                ;
        }
        dataFile.close();
    }
    else 
    {
        throw std::runtime_error("Error opening data!");
    }
}

void    BitcoinExchange::crossCheckInput(char *fileName)
{
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) 
    {
        std::string line;
        while (std::getline(inputFile, line))
        {   
            if (line == "date | value")
                continue ;
            size_t barPos = line.find("|");
            if (barPos == std::string::npos)
            {
                std::cout << "Bad input: " << line << std::endl;
                continue;
            }
            std::string date = line.substr(0, barPos - 1);
            if (dateValid(date) == false)
            {
                std::cout << "Invalid date: " << date << std::endl;
                continue;
            }
            std::string factorStr = line.substr(barPos + 2);
            double factor = convertFactor(factorStr);
            if (factor == -1)
                continue;
            calculateBtcValue(date, factor);
        }
        inputFile.close();
    }
    else 
    {
        throw std::runtime_error("Error opening input file!");
    }
}

bool    BitcoinExchange::dateValid(std::string date)
{
    size_t minSignCount = 0;
    for (size_t i = 0; i < date.size(); i++)
    {    
        if (date[i] == '-') 
            minSignCount++;
    }
    if (minSignCount != 2)
        return false;
    size_t      firstMinPos = date.find("-");
    size_t      lastMinPos = date.rfind("-");

    // year
    std::string yearString = date.substr(0, firstMinPos);
    // std::cout << yearString << std::endl;
    if (yearString.empty())
        return false;
    std::istringstream yearStream(yearString);
    int year;
    if (!(yearStream >> year) || year < CHRIST_WAS_BORN || year > ENTROPY_DOSNT_ALLOW)
        return false;
    // month
    std::string monthString = date.substr(firstMinPos + 1, lastMinPos);
    if (monthString.empty())
        return false;
    std::istringstream monthStream(monthString);
    int month;
    if (!(monthStream >> month) || month < 1 || month > 12)
        return false;
    int daysInMonth[] = {0, JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap)
        daysInMonth[2] = FEBRUARY + 1;
    // day 
    std::string dayString = date.substr(lastMinPos + 1);
    if (dayString.empty())
        return false;
    std::istringstream dayStream(dayString);
    int day;
    if (!(dayStream >> day) || day < 0 || day > daysInMonth[month])
        return false;
    return true;
}

double     BitcoinExchange::convertFactor(std::string factorString)
{
    std::istringstream factorStream(factorString);
    double factor;
    if (!(factorStream >> factor))
    {
        std::cout << "Invalid factor." << std::endl;
        return (-1);
    }
    else if (factor < CHRIST_WAS_BORN)
    {
        std::cout << "Negative number." << std::endl;
        return (-1);
    }
    else if (factor > INT_MAX)
    {
        std::cout << "Too large number." << std::endl;
        return (-1);
    }
    else
        return factor;
}

void    BitcoinExchange::calculateBtcValue(std::string date, double factor)
{
    std::map<std::string, double>::iterator it;
    it = data.lower_bound(date);
    if (it == data.end() || (it->first != date && it != data.begin()))
        --it;
    std::cout << date << " => " << factor << " => " << (it->second * factor) << std::endl; 
}
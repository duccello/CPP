#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <climits>

#define JANUARY 31
#define FEBRUARY 28
#define MARCH 31 
#define APRIL 30
#define MAY 31
#define JUNE 30
#define JULY 31
#define AUGUST 31 
#define SEPTEMBER 30
#define OCTOBER 31
#define NOVEMBER 30 
#define DECEMBER 31
#define CHRIST_WAS_BORN 0
//#define BITCOIN_WAS_BORN 2009
#define ENTROPY_DOSNT_ALLOW 2026

class BitcoinExchange
{
  private:
      std::map<std::string, double> data;

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void    loadData(void);
    void    crossCheckInput(char *fileName);
    bool    dateValid(std::string date);
    double     convertFactor(std::string factorStr);
    void    calculateBtcValue(std::string date, double factor);
};

#endif

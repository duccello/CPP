#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "btc needs an input file" << std::endl;
        return (1);
    }
    BitcoinExchange btc;
    try
    {
        btc.loadData();
        btc.crossCheckInput(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
    return (0);
}
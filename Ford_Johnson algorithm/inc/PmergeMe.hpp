#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <sstream>
#include <climits>
#include <algorithm>

std::vector<int> fordJohnsonVector(const std::vector<int>& input);
std::list<int>   fordJohnsonList(const std::list<int>& input);

struct Pair
{
    int small;
    int large;
};

template <typename Container>
Container parseInputToContainer(size_t size, char **argv)
{
    Container input;
    double    num = 0;

    for (size_t i = 1; i < size; i++)
    {
        std::istringstream iss(argv[i]);
        if (iss >> num && num >= 0 && num <= INT_MAX)
            input.push_back(static_cast<int>(num));
        else
            throw std::runtime_error("Invalid input.");
    }
    return input;
}

template <typename Container>
Container jacobsthal(size_t count)
{
    Container jac;
    jac.push_back(0);
    jac.push_back(1);

    while (jac.back() < count)
    {
        typename Container::const_iterator last = jac.end();
        --last;

        typename Container::const_iterator secondLast = last;
        --secondLast;

        jac.push_back(*last + 2 * *secondLast);
    }
    return jac;
}

template <typename Container>
Container insertionOrder(size_t pendSize)
{
    Container jac = jacobsthal<Container>(pendSize + 2);
    Container order;
    size_t prev = 1;
    typename Container::const_iterator it = jac.begin();
    std::advance(it, 2);

    for (; it != jac.end(); ++it)
    {
        size_t curr = *it;

        if (prev >= pendSize)
            break;

        size_t hi = std::min(curr, pendSize + 1);

        for (size_t idx = hi; idx > prev; --idx)
        {
            if (idx - 2 < pendSize)
                order.push_back(idx - 2);
        }

        prev = curr;
    }
    for (size_t i = 0; i < pendSize; ++i)
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }
    return order;
}
#endif

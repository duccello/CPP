#include "PmergeMe.hpp"

//vector
std::vector<int> fordJohnsonVector(const std::vector<int>& input)
{
    //recursive comparation of pairs
    if (input.size() <= 1)
        return input;
    std::vector<Pair> pairs;
    bool hasOdd = (input.size() % 2 != 0);
    int odd = 0;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        Pair p;
        if (input[i] < input[i + 1])
        {
            p.small = input[i];
            p.large = input[i + 1];
        }
        else
        {
            p.small = input[i + 1];
            p.large = input[i];
        }
        pairs.push_back(p);
    }
    if (hasOdd)
        odd = input.back();
    std::vector<int> large;
    for (std::vector<Pair>::const_iterator sortedIt = pairs.begin(); sortedIt != pairs.end(); sortedIt++)
        large.push_back(sortedIt->large);
    std::vector<int> sortedLarge = fordJohnsonVector(large);
//sorting them
    std::vector<Pair> sortedPairs;
    for (std::vector<int>::const_iterator largeIt = sortedLarge.begin(); largeIt != sortedLarge.end(); largeIt++)
    {
        for (std::vector<Pair>::iterator pairsIt = pairs.begin(); pairsIt != pairs.end(); pairsIt++)
        {
            if (pairsIt->large == *largeIt)
            {
                sortedPairs.push_back(*pairsIt);
                pairs.erase(pairsIt);
                break;
            }
        }
    }
//create chain of larger values ("main")
    std::vector<int> chain;
    chain.push_back(sortedPairs[0].small);
    for (std::vector<Pair>::const_iterator sortedIt = sortedPairs.begin(); sortedIt != sortedPairs.end(); sortedIt++)
        chain.push_back(sortedIt->large);
//insert the rest ("pend")  
    std::vector<size_t> order = insertionOrder<std::vector<size_t> >(sortedPairs.size() - 1);
    for (size_t oi = 0; oi < order.size(); oi++)
    {
        size_t idx = order[oi];
        std::vector<int>::iterator boundIt = std::find(chain.begin(), chain.end(), sortedPairs[idx + 1].large);
        std::vector<int>::iterator chainIt = std::upper_bound(chain.begin(), boundIt, sortedPairs[idx + 1].small);
        chain.insert(chainIt, sortedPairs[idx + 1].small);
    }
//odd ball
    if (hasOdd)
    {
        std::vector<int>::iterator chainIt = std::upper_bound(chain.begin(), chain.end(), odd);
        chain.insert(chainIt, odd);
    }
    return chain;
}

//list
std::list<int> fordJohnsonList(const std::list<int>& input)
{
    //recursive comparation of pairs
    if (input.size() <= 1)
        return input;
    std::list<Pair> pairs;
    bool hasOdd = (input.size() % 2 != 0);
    int odd = 0;

    std::list<int>::const_iterator it = input.begin();
    while (it != input.end())
    {
        std::list<int>::const_iterator it2 = it;
        ++it2;

        if (it2 == input.end())
            break;

        Pair p;

        if (*it < *it2)
        {
            p.small = *it;
            p.large = *it2;
        }
        else
        {
            p.small = *it2;
            p.large = *it;
        }

        pairs.push_back(p);

        it = it2;
        it++;
    }
    if (hasOdd)
        odd = input.back();
    std::list<int> large;
    for (std::list<Pair>::const_iterator sortedIt = pairs.begin(); sortedIt != pairs.end(); sortedIt++)
        large.push_back(sortedIt->large);
    std::list<int> sortedLarge = fordJohnsonList(large);
//sorting them
    std::list<Pair> sortedPairs;
    for (std::list<int>::const_iterator largeIt = sortedLarge.begin(); largeIt != sortedLarge.end(); largeIt++)
    {
        for (std::list<Pair>::iterator pairsIt = pairs.begin(); pairsIt != pairs.end(); pairsIt++)
        {
            if (pairsIt->large == *largeIt)
            {
                sortedPairs.push_back(*pairsIt);
                pairs.erase(pairsIt);
                break;
            }
        }
    }
//create chain of larger values ("main")
    std::list<int> chain;
    chain.push_back(sortedPairs.begin()->small);
    for (std::list<Pair>::const_iterator sortedIt = sortedPairs.begin(); sortedIt != sortedPairs.end(); sortedIt++)
        chain.push_back(sortedIt->large);
//insert the rest ("pend")  
    std::list<size_t> order = insertionOrder<std::list<size_t> >(sortedPairs.size() - 1);
    for (std::list<size_t>::const_iterator oit = order.begin(); oit != order.end(); oit++)
    {
        std::list<Pair>::const_iterator sortedIt = sortedPairs.begin();
        std::advance(sortedIt, *oit + 1);
        std::list<int>::iterator chainIt = chain.begin();
        while (chainIt != chain.end() && *chainIt != sortedIt->large && *chainIt < sortedIt->small)
            chainIt++;
        chain.insert(chainIt, sortedIt->small);
    }
//odd ball
    if (hasOdd)
    {
        std::list<int>::iterator chainIt = chain.begin();
        while (chainIt != chain.end() && *chainIt < odd)
            chainIt++;
        chain.insert(chainIt, odd);
    }
    return chain;
}
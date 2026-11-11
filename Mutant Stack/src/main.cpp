#include "MutantStack.hpp"
#include <unistd.h>

#define SIZE 10
int main(void)
{
    std::cout << "\033[2J\033[H";

    MutantStack<int> mStack;
    for (int i = 0; i < SIZE; i++)
        mStack.push(i);
    
    std::cout << "\n\033[38;5;90mWe made a Mutant stack " << std::endl;
    std::cout << "Size: " << mStack.size() << std::endl;
    std::cout << "Top: " << mStack.top() << std::endl;
    sleep(2);
    mStack.pop();
    std::cout << "\n\033[38;5;89mAfter succssefull pop..." << std::endl;
    std::cout << "Size: " << mStack.size() << std::endl;
    std::cout << "Top: " << mStack.top() << std::endl;
    sleep(2);
    std::cout << "\n\033[38;5;85mNow iterating thru the MutantStack we see: \n"; 
    MutantStack<int>::iterator it = mStack.begin();
    MutantStack<int>::iterator end = mStack.end();
    while (it != end)
        std::cout << *it++ << std::endl;
    sleep(2); 
    std::stack<int> stackCopy(mStack);
    std::cout << "\n\033[38;5;80mThen created a regular stack copied of our Mutant one:\n";
    std::cout << "Size: " << stackCopy.size() << std::endl;
    std::cout << "Top: " << stackCopy.top() << std::endl;
    return 0;
}
#include "PmergeMe.hpp"
#include <ctime>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	try
	{
	//before
		std::cout << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << " " << argv[i];
		std::cout << std::endl;

	//vector 
		clock_t vectorBegin = clock();
		std::vector<int> vecMe = parseInputToContainer<std::vector<int> >(argc, argv);
		vecMe = fordJohnsonVector(vecMe);
		clock_t vectorDuration = clock() - vectorBegin;

	//list
		clock_t listBegin = clock();
		std::list<int>   listMe  = parseInputToContainer<std::list<int> >(argc, argv);
		listMe = fordJohnsonList(listMe);
		clock_t listDuration = clock() - listBegin;
	
	//aftermath
		std::cout << "After: ";
		for (size_t i = 0; i < vecMe.size(); i++)
			std::cout << " " << vecMe.at(i);
		std::cout << std::endl;
		std::cout << "Time to process a range of 5 elements with std::vector: " << (double)vectorDuration / CLOCKS_PER_SEC << " seconds." << std::endl;
		std::cout << "Time to process a range of 5 elements with std::list: "<<  (double)listDuration / CLOCKS_PER_SEC << " seconds." << std::endl;

	}
	catch (const std::runtime_error& error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

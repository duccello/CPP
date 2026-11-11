/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:14:20 by duccello          #+#    #+#             */
/*   Updated: 2025/11/24 15:14:22 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <cstring>
#include <string>

int	main(void)
{
	PhoneBook	my_book;
	int			index;

	index = 0;
	std::string input;
	while (true)
	{
		std::getline(std::cin, input);
		if (!std::cin)
			return (0);
		if (input == "ADD")
		{
			std::cout << "\033[2J\033[H";
			my_book.add_contact(&index);
		}
		else if (input == "SEARCH")
		{
			std::cout << "\033[2J\033[H";
			my_book.display_list();
		}
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Please, try again" << std::endl;
	}
	return (0);
}

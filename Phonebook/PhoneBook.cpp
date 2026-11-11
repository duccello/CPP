/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:01:56 by duccello          #+#    #+#             */
/*   Updated: 2025/11/24 15:02:28 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <sstream>
#include <string>

// PhoneBook class functions
PhoneBook::PhoneBook(void)
{
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "\033[38;5;208mThis is my Awsome Phone Book!" << std::endl;
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|INDEX_____|FIRST_NAME|LAST_NAME_|NICK_NAME_|" << std::endl;
	for (int i = 0; i < 8; i++)
		std::cout << "|_________" << i
			+ 1 << "|__________|__________|__________|" << std::endl;
	std::cout << "type 'ADD' to add a contact" << std::endl;
	std::cout << "type 'SEARCH' to search for a contact" << std::endl;
	std::cout << "type 'EXIT' to exit" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::add_contact(int *index)
{
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "\033[38;5;208mPlease fill all the relevant fields:" << std::endl;
	list[*index].set_first_name();
	list[*index].set_last_name();
	list[*index].set_nick_name();
	list[*index].set_phone_number();
	list[*index].set_darkest_secret();
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "Contact " << *index + 1 << " added to the list!" << std::endl;
	std::cout << "type 'ADD' to add a contact" << std::endl;
	std::cout << "type 'SEARCH' to search for a contact" << std::endl;
	std::cout << "type 'EXIT' to exit" << std::endl;
	*index += 1;
	if (*index == 8)
		*index = 0;
}

void PhoneBook::display_list(void)
{
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|INDEX_____|FIRST_NAME|LAST_NAME_|NICK_NAME_|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|_________" << i + 1;
		std::cout << "|" << list[i].get_first_name(false);
		std::cout << "|" << list[i].get_last_name(false);
		std::cout << "|" << list[i].get_nick_name(false);
		std::cout << "|" << std::endl;
	}
	select_contact();
	return ;
}

void PhoneBook::select_contact(void)
{
	int	number;

	std::string contact_selected;
	std::cout << "Indicate with a number from 1 to 8 wich contact to expand." << std::endl;
	while (true)
	{
		std::getline(std::cin, contact_selected);
		if (!std::cin)
			exit(EXIT_SUCCESS);
		std::stringstream ss(contact_selected);
		if (!(ss >> number))
		{
			std::cout << "Only numeric values" << std::endl;
			continue ;
		}
		else if (number < 1 || number > 8)
		{
			std::cout << "Must be a number between 1 and 8" << std::endl;
			continue ;
		}
		else
			break ;
	}
	display_contact(number - 1);
}

void PhoneBook::display_contact(int n)
{
	std::cout << "\033[2J\033[H" << std::endl;
	std::cout << "First name:" << list[n].get_first_name(true) << std::endl;
	std::cout << "Last name: " << list[n].get_last_name(true) << std::endl;
	std::cout << "Nick name: " << list[n].get_nick_name(true) << std::endl;
	std::cout << "Phone number: " << list[n].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << list[n].get_darkest_secret() << std::endl;
	std::cout << std::endl;
	std::cout << "type 'ADD' to add a contact" << std::endl;
	std::cout << "type 'SEARCH' to search for a contact" << std::endl;
	std::cout << "type 'EXIT' to exit" << std::endl;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:21:11 by duccello          #+#    #+#             */
/*   Updated: 2025/12/01 13:45:18 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_first_name(void)
{
	while (true)
	{
		std::cout << "First name:" << std::endl;
		std::getline(std::cin, this->first_name);
		if (!std::cin)
			exit(EXIT_SUCCESS);
		if (first_name.length() < 1)
		{
			std::cout << "\033[2J\033[H" << std::endl;
			std::cout << "\033[38;5;208mPlease try again!" << std::endl;
			continue ;
		}
		return ;
	}
}

void Contact::set_last_name(void)
{
	while (true)
	{
		std::cout << "Last name:" << std::endl;
		std::getline(std::cin, this->last_name);
		if (!std::cin)
			exit(EXIT_SUCCESS);
		if (last_name.length() < 1)
		{
			std::cout << "\033[2J\033[H" << std::endl;
			std::cout << "\033[38;5;208mPlease try again!" << std::endl;
			continue ;
		}
		return ;
	}
}

void Contact::set_nick_name(void)
{
	while (true)
	{
		std::cout << "Nickname:" << std::endl;
		std::getline(std::cin, this->nick_name);
		if (!std::cin)
			exit(EXIT_SUCCESS);
		if (nick_name.length() < 1)
		{
			std::cout << "\033[2J\033[H" << std::endl;
			std::cout << "\033[38;5;208mPlease try again!" << std::endl;
			continue ;
		}
		return ;
	}
}

void Contact::set_phone_number(void)
{
	while (true)
	{
		std::cout << "Phone number:" << std::endl;
		std::getline(std::cin, this->phone_number);
		if (!std::cin)
			exit(EXIT_SUCCESS);
		if (phone_number.length() < 1)
		{
			std::cout << "\033[2J\033[H" << std::endl;
			std::cout << "\033[38;5;208mPlease try again!" << std::endl;
			continue ;
		}
		return ;
	}
}

void Contact::set_darkest_secret(void)
{
	while (true)
	{
		std::cout << "Darkest secret:" << std::endl;
		std::getline(std::cin, this->darkest_secret);
		if (!std::cin)
			exit(EXIT_SUCCESS);
		if (darkest_secret.length() < 1)
		{
			std::cout << "\033[2J\033[H" << std::endl;
			std::cout << "\033[38;5;208mPlease try again!" << std::endl;
			continue ;
		}
		return ;
	}
}

std::string Contact::get_first_name(bool full)
{
	if (full == true)
		return (first_name);
	else
	{
		if (first_name.length() > 10)
			return (first_name.substr(0, 9) + ".");
		else if (first_name.length() < 10)
			return (std::string(10 - first_name.length(), '_') + first_name);
		else
			return (first_name);
	}
}

std::string Contact::get_last_name(bool full)
{
	if (full == true)
		return (last_name);
	else
	{
		if (last_name.length() > 10)
			return (last_name.substr(0, 9) + ".");
		else if (last_name.length() < 10)
			return (std::string(10 - last_name.length(), '_') + last_name);
		else
			return (last_name);
	}
}

std::string Contact::get_nick_name(bool full)
{
	if (full == true)
		return (nick_name);
	else
	{
		if (nick_name.length() > 10)
			return (nick_name.substr(0, 9) + ".");
		else if (nick_name.length() < 10)
			return (std::string(10 - nick_name.length(), '_') + nick_name);
		else
			return (nick_name);
	}
}

std::string Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}

std::string Contact::get_phone_number(void)
{
	return (phone_number);
}

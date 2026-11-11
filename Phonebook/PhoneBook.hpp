/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:14:05 by duccello          #+#    #+#             */
/*   Updated: 2025/11/24 15:14:07 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact();
	~Contact();
	void set_first_name(void);
	void set_last_name(void);
	void set_nick_name(void);
	void set_phone_number(void);
	void set_darkest_secret(void);

	std::string get_first_name(bool full);
	std::string get_last_name(bool full);
	std::string get_nick_name(bool full);
	std::string get_phone_number(void);
	std::string get_darkest_secret(void);
};

class PhoneBook
{
  private:
	Contact list[8];

  public:
	PhoneBook(void);
	~PhoneBook(void);

	void add_contact(int *index);
	void display_list(void);
	void select_contact(void);
	void display_contact(int n);
};

#endif
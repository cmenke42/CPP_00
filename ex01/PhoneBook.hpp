/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:49 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/07 23:43:02 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


// define some coolor macros
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"

class PhoneBook
{
	public:
		PhoneBook(/* args */);
		~PhoneBook();
	private:
		Contact contacts[8];
		int		_contact_count;
		int		_contact_index;
		/* data */
};

PhoneBook::PhoneBook(void) : contacts(), _contact_count(0), _contact_index(0)
{
}

PhoneBook::~PhoneBook()
{
}

// void	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
// {
// 	this->contacts[this->_contact_count].set_first_name(first_name);
// 	this->contacts[this->_contact_count].set_last_name(last_name);
// 	this->contacts[this->_contact_count].set_nickname(nickname);
// 	this->contacts[this->_contact_count].set_phone_number(phone_number);
// 	this->contacts[this->_contact_count].set_darkest_secret(darkest_secret);
// 	// this->contac_index++;
// 	this->_contact_count++;
// 	std::cout << "Contact added" << std::endl;
// 	std::cout << "Contact count: " << this->_contact_count << std::endl;
// }

#endif /* PHONEBOOK_HPP */
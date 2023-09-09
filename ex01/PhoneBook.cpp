/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:46 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/09 19:29:37 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	trimm_string(std::string& user_input);
bool		is_input_valid(const std::string& user_input);

PhoneBook::PhoneBook(void) : _contact_count(0), _contact_index(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact(void)
{
	std::string		user_input;
	int	i;

	i = 0;
	while (i < Contact::field_count)
	{
		std::cout << "Please enter " << Contact::fields[i] << ": ";
		std::getline(std::cin, user_input);
		user_input = trimm_string(user_input);
		if (!is_input_valid(user_input))
			continue ;
		(this->_contacts[this->_contact_index].*Contact::setters[i])(user_input);
		i++;
	}
	if (this->_contact_count < 8)
		this->_contact_count++;
	if (this->_contact_index < 7)
		this->_contact_index++;
	else
		this->_contact_index = 0;
}

bool	is_input_valid(const std::string& user_input)
{

	if (user_input.length() == 0 || user_input.find_first_of(" \t") == std::string::npos)
	{
		std::cerr << RED "Error: Input cannot be empty" RESET << std::endl;
		return (false);
	}
	return (true);
}

std::string	trimm_string(std::string& user_input)
{
	std::string 		word;
	std::string			trimmed_string;
	std::stringstream	user_input_stream(user_input);

	while (user_input_stream >> word)
	{
		if (trimmed_string.length() > 0)
			trimmed_string += " ";
		trimmed_string += word;
	}
	return (trimmed_string);
}

void	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:46 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/06 23:20:07 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	trimm_string(std::string& user_input);
bool		is_input_valid(const std::string& user_input);
void		display_contact_list_element(const Contact& contact, const int index);
void		display_complete_contact(const Contact& contact);

PhoneBook::PhoneBook(void) : _contact_count(0), _contact_index(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add_contact(void)
{
	std::string		user_input;
	int				i;
	int				error_count;

	i = 0;
	error_count = 0;
	while (i < Contact::field_count)
	{
		std::cout << "Please enter " << Contact::fields[i] << ": ";
		std::getline(std::cin, user_input);
		user_input = trimm_string(user_input);
		if (!is_input_valid(user_input))
		{
			if (error_count++ == 2)
			{
				std::cerr << "Error: Too many invalid inputs" << std::endl;
				return ;
			}
			continue ;
		}
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

bool	is_input_valid(const std::string& user_input)
{

	if (user_input.length() == 0 || user_input.find_first_not_of(" \t") == std::string::npos)
	{
		std::cerr << "Error: Input cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

bool	PhoneBook::display_entry_overview(void) const
{
	std::string		user_input;
	int				i;

	if (this->_contact_count == 0)
	{
		std::cout << "Error: No contacts to display" << std::endl;
		return (false);
	}
	i = 0;
	while (i < this->_contact_count)
	{
		display_contact_list_element(this->_contacts[i], i);
		i++;
	}
	return (true);
}

void	display_contact_list_element(const Contact& contact, const int index)
{
	std::string	contact_detail;
	int			i;

	i = 0;
	std::cout << std::setw(10) << std::right << std::setfill(' ');
	std::cout << index << "|";
	while (i < Contact::field_count && i < 3)
	{
		contact_detail = (contact.*Contact::getters[i])();
		if (contact_detail.length() > 10)
		{
			contact_detail[9] = '.';
			contact_detail[10] = 0;
		}
		std::cout << std::setw(10) << std::right << std::setfill(' ');
		std::cout << contact_detail.c_str() << "|";
		i++;
	}
	std::cout << std::endl;
}

bool	PhoneBook::display_entry(const int index) const
{
	if (index < 0 || index > this->_contact_count - 1)
	{
		std::cerr << "Error: Invalid index entered" << std::endl;
		std::cerr << "Range is: 0 till " << this->_contact_count - 1 << std::endl;
		return (false);
	}
	display_complete_contact(this->_contacts[index]);
	return (true);
}

void	display_complete_contact(const Contact& contact)
{
	int	i;
	int	padding;
	int	field_length;

	i = 0;
	padding = 0;
	while (i < Contact::field_count)
	{
		field_length = Contact::fields[i].length();
		if (field_length > padding)
			padding = field_length;
		i++;
	}
	i = 0;
	while (i < Contact::field_count)
	{
		std::cout << std::setw(padding) << std::left << std::setfill(' ');
		std::cout << Contact::fields[i] << ": " << (contact.*Contact::getters[i])() << std::endl;
		i++;
	}
}

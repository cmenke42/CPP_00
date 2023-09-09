/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:41 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/09 19:34:20 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_initialize_setters();
	return ;
}

Contact::~Contact()
{
	return ;
}

// Static variables
std::string Contact::fields[5] = {
    "first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

void (Contact::*Contact::setters[5])(std::string&) = {
    &Contact::set_first_name,
    &Contact::set_last_name,
    &Contact::set_nickname,
    &Contact::set_phone_number,
    &Contact::set_darkest_secret
};

std::string (Contact::*Contact::getters[5])(void) = {
	&Contact::get_first_name,
	&Contact::get_last_name,
	&Contact::get_nickname,
	&Contact::get_phone_number,
	&Contact::get_darkest_secret
};

int			Contact::field_count = 5;

// Setters
void	Contact::set_first_name(std::string& first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string& last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string& nickname)
{
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string& phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string& darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void	Contact::_initialize_setters(void)
{
	this->setters[0] = &Contact::set_first_name;
	this->setters[1] = &Contact::set_last_name;
	this->setters[2] = &Contact::set_nickname;
	this->setters[3] = &Contact::set_phone_number;
	this->setters[4] = &Contact::set_darkest_secret;
}

// Getters
std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

std::string Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}

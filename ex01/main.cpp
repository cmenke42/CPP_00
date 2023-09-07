/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:29:56 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/07 22:14:55 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

bool	get_string(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	return (true);
}

// bool	add_contact(PhoneBook &phonebook)
// {
// 	std::string	string_entered;

// 	std::cout << "Please enter the contact's first name: " << std::endl;
// 	std::getline(std::cin, first_name);
// 	std::cout << "Please enter the contact's last name: " << std::endl;
// 	std::getline(std::cin, last_name);
// 	std::cout << "Please enter the contact's nickname: " << std::endl;
// 	std::getline(std::cin, nickname);
// 	std::cout << "Please enter the contact's phone number: " << std::endl;
// 	std::getline(std::cin, phone_number);
// 	std::cout << "Please enter the contact's darkest secret: " << std::endl;
// 	std::getline(std::cin, darkest_secret);
// 	return (true);
// }

int	main(void)
{
	PhoneBook		crappy_phonebook;
	std::string		command_entered;

	while (1)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, command_entered);
		if (command_entered == "EXIT")
			break ;
		// else if (command_entered == "ADD")
		// 	add_contact(crappy_phonebook);
		else if (command_entered == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else
			std::cerr << "Invalid command entered" << std::endl;
	}
}


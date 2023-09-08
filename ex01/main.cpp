/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:29:56 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/07 23:45:37 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

bool	get_string(std::string &user_input)
{
	std::getline(std::cin, user_input);
	if (std::cin.eof() || user_input.empty())
		return (false);
	return (true);
}

bool	add_contact(PhoneBook &phonebook)
{
	std::string		ask_for_strings[5];
	std::string		user_input;
	int				i;

	ask_for_strings[0] = "Please enter the contact's first name: ";
	ask_for_strings[1] = "Please enter the contact's last name: ";
	ask_for_strings[2] = "Please enter the contact's nickname: ";
	ask_for_strings[3] = "Please enter the contact's phone number: ";
	ask_for_strings[4] = "Please enter the contact's darkest secret: ";

	i = 0;
	while (i < 5)
	{
		std::cout << ask_for_strings[i];
		if (!get_string(user_input))
			std::cerr << RED "Error: String needs to be at least one character long" RESET << std::endl;
		else
		{
			// switch (i)
			// {
			// case 0:
			// 	set_first_name(user_input);
			// 	break;
			// case 1:
			// 	set_last_name(user_input);
			// 	break;
			// case 2:
			// 	set_nickname(user_input);
			// 	break;
			// case 3:
			// 	set_phone_number(user_input);
			// 	break;
			// case 4:
			// 	set_darkest_secret(user_input);
			// 	break;
			// }
			i++;
		}
	}
	return (true);
}

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
		else if (command_entered == "ADD")
			add_contact(crappy_phonebook);
		else if (command_entered == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else
			std::cerr << RED "Error: Invalid command entered" RESET << std::endl;
	}
}


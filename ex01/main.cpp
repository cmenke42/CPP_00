/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:29:56 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/10 16:59:32 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	display_one_contact(PhoneBook& crappy_phonebook);

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
			crappy_phonebook.add_contact();
		else if (command_entered == "SEARCH")
		{
			if (!crappy_phonebook.display_entry_overview())
				continue ;
			display_one_contact(crappy_phonebook);
		}
		else
			std::cerr << RED "Error: Invalid command entered" RESET << std::endl;
	}
	return (0);
}

void	display_one_contact(PhoneBook& crappy_phonebook)
{
	std::string			input;
	int					index;
	int					i;
	
	i = 0;
	while (i < 3)
	{
		std::cout << "Please enter the index of an entry: ";
		std::getline(std::cin, input);
		std::istringstream	integer_stream(input);
		if (integer_stream >> index)
		{
			if (crappy_phonebook.display_entry(index))
				return ;
		}
		else
			std::cerr << RED "Error: Invalid index entered" RESET << std::endl;
		i++;
	}
	std::cerr << RED "Error: Too many invalid indexes entered" RESET << std::endl;
}

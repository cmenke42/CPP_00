/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:29:56 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/06 15:39:46 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

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
			std::cout << "ADD" << std::endl;
		else if (command_entered == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else
			std::cerr << "Invalid command entered" << std::endl;
	}
}
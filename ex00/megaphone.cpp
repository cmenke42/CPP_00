/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:01:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/10/06 22:55:02 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	print_string_in_uppercase(const std::string& string);

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (*(++argv))
		{
			print_string_in_uppercase(*argv);
			if (*(argv + 1))
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}

void	print_string_in_uppercase(const std::string& string)
{
	size_t	start;
	size_t	end;

	start = string.find_first_not_of(' ');
	end = string.find_last_not_of(' ');
	if (start == std::string::npos || end == std::string::npos)
		return ;
	while (start <= end)
	{
		std::cout << (char)std::toupper(string[start]);
		start++;
	}
}

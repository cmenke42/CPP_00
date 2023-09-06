/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:49 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/06 15:46:51 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(/* args */);
		~PhoneBook();
	private:
		Contact contacts[8];
		// int		contact_count;
		/* data */
};

PhoneBook::PhoneBook(void) : contacts()
{
}

PhoneBook::~PhoneBook()
{
}


#endif /* PHONEBOOK_HPP */
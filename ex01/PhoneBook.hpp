/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:49 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/09 19:22:50 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <sstream>


// define some color macros
#define RESET		"\033[0m"
#define RED			"\033[31m"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		void	search_contact(void);
	private:
		Contact		_contacts[8];
		int			_contact_count;
		int			_contact_index;
};

#endif /* PHONEBOOK_HPP */
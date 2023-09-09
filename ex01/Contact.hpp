/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:19:43 by cmenke            #+#    #+#             */
/*   Updated: 2023/09/09 21:33:08 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		static std::string	fields[5];
		static int			field_count;
		static void			(Contact::*setters[5])(std::string&);
		static std::string	(Contact::*getters[5])(void);

		void		set_first_name(std::string& first_name);
		void		set_last_name(std::string& last_name);
		void		set_nickname(std::string& nickname);
		void		set_phone_number(std::string& phone_number);
		void		set_darkest_secret(std::string& darkest_secret);

		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif //CONTACT_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:13:45 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/13 17:25:06 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phone_bot.h"

class Contact
{
	public:
		Contact();
		Contact(std::string data[5]);
		~Contact();
		
		void		print_contacts(unsigned int index, Contact contact[8]);
		bool		print_infos(unsigned int index, Contact contact[8]);
		std::string	get_first_name(Contact contact);
		std::string	get_last_name(Contact contact);
		std::string	get_nickname(Contact contact);
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif

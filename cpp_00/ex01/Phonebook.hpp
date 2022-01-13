/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:17:18 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/13 16:48:23 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
	public:
		Phonebook();
		~Phonebook();
		
		unsigned int	index;
		Contact			contact[8];
		bool			get_cmd();
	private:
		bool			_add_first_name(std::string *data);
		bool			_add_last_name(std::string *data);
		bool			_add_nickname(std::string *data);
		bool			_add_phone_number(std::string *data);
		bool			_add_darkest_secret(std::string *data);
		void			_wrong_cmd();
		bool			_next_request();
		bool			_add_cmd();
		bool			_search_cmd();
		bool			_exit_cmd();
};

#endif

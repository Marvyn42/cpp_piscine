/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:13:56 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/13 03:34:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::Contact(std::string data[5]) : _first_name(data[0]), _last_name(data[1]), 
										_nickname(data[2]), _phone_number(data[3]),
										_darkest_secret(data[4]) {
}

Contact::~Contact() {
}

void	print_contacts(int index) {
	for (size_t i = 0; i < index; i++) {
		/* code */
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:13:56 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 15:41:41 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
**	constructeur
*/
Contact::Contact() {
}

/*
**	constructeur avec initialisation de données
*/
Contact::Contact(std::string data[5]) : _first_name(data[0]), _last_name(data[1]), 
										_nickname(data[2]), _phone_number(data[3]),
										_darkest_secret(data[4]) {
}

/*
**	destructeur
*/
Contact::~Contact() {
}

/*
**	Renvoi string first name en fonction de sa longueur
*/
std::string	Contact::get_first_name(Contact contact) const {
	if (contact._first_name.length() >= 10)
		contact._first_name = contact._first_name.substr(0, 9) + '.';
	return (contact._first_name);
}

/*
**	Renvoi string last name en fonction de sa longueur
*/
std::string	Contact::get_last_name(Contact contact) const {
	if (contact._last_name.length() >= 10)
		contact._last_name = contact._last_name.substr(0, 9) + '.';
	return (contact._last_name);
}

/*
**	Renvoi string nickname en fonction de sa longueur
*/
std::string	Contact::get_nickname(Contact contact) const {
	if (contact._nickname.length() >= 10)
		contact._nickname = contact._nickname.substr(0, 9) + '.';
	return (contact._nickname);
}

/*
**	Affiche les informations du contact indiqué par l'utilisateur
*/
bool	Contact::print_infos(unsigned int index, Contact contact[8]) const {
	std::string		tmp;
	unsigned int	i;

	std::cout << "(っ◔◡◔)っ: ℙ𝕝𝕖𝕒𝕤𝕖, 𝕤𝕖𝕝𝕖𝕔𝕥 𝕒𝕟 𝕚𝕟𝕕𝕖𝕩 𝕓𝕖𝕥𝕨𝕖𝕖𝕟 0 𝕒𝕟𝕕 " << index - 1;
	std::cout << std::endl << ">";
	if (!std::getline(std::cin, tmp)) {
			std::cerr << "Error getline. Exit." << std::endl;
			return (false);
	}
	i = (unsigned int)atoi(tmp.c_str());
	while (tmp.length() != 1 || std::isdigit(tmp.at(0)) == 0 || i >= index) {
		std::cout << "(╯`Д´）╯︵ ┻━┻: ℙ𝕝𝕖𝕒𝕤𝕖, 𝕕𝕠𝕟'𝕥 𝕗𝕦𝕔𝕜 𝕨𝕚𝕥𝕙 𝕞 𝕖..." << std::endl;
		std::cout << "𝕤𝕖𝕝𝕖𝕔𝕥 𝕒𝕟 𝕚𝕟𝕕𝕖𝕩 𝕓𝕖𝕥𝕨𝕖𝕖𝕟 0 𝕒𝕟𝕕 " << index - 1 << std::endl << ">";
		if (!std::getline(std::cin, tmp)) {
			std::cerr << "Error getline. Exit." << std::endl;
			return (false);
		}
		i = (unsigned int)atoi(tmp.c_str());
	}
	std::cout << "ℍ𝕚𝕤 𝕗𝕚𝕣𝕤𝕥 𝕟𝕒𝕞 𝕖:\t[" << contact[i]._first_name << "]" << std::endl;
	std::cout << "ℍ𝕚𝕤 𝕝𝕒𝕤𝕥 𝕟𝕒𝕞 𝕖:\t\t[" << contact[i]._last_name << "]" << std::endl;
	std::cout << "ℍ𝕚𝕤 𝕟𝕚𝕔𝕜𝕟𝕒𝕞 𝕖:\t\t[" << contact[i]._nickname << "]" << std::endl;
	std::cout << "ℍ𝕚𝕤 𝕡𝕙𝕠𝕟𝕖 𝕟𝕦𝕞 𝕓𝕖𝕣:\t[" << contact[i]._phone_number << "]" << std::endl;
	std::cout << "ℍ𝕚𝕤 𝕕𝕒𝕣𝕜𝕤𝕖𝕔𝕣𝕖𝕥:\t\t[" << contact[i]._darkest_secret << "]" << std::endl;
	return (true);
}

/*
**	Affiche le tableau contenant tout les contacts
*/
void	Contact::print_contacts(unsigned int index, Contact contact[8]) {
	std::cout << std::endl << "|-----index|first name|-last name|--nickname|" << std::endl;
	for (size_t i = 0; i < index; i++) {
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << this->get_first_name(contact[i]) << "|";
		std::cout << std::right << std::setw(10) << this->get_last_name(contact[i]) << "|";
		std::cout << std::right << std::setw(10) << this->get_nickname(contact[i]) << "|";
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "" << std::endl;
}

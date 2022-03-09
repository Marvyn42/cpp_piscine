/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:17:15 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/01 15:50:28 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "phone_bot.h"

/*
**	Constructeur
*/
Phonebook::Phonebook() : index(0), scd_index(0) {
	std::cout << "\\(^◇^)/: ℍ𝕚 𝕤𝕚𝕣. 𝕐𝕠𝕦 𝕔𝕒𝕟 𝕔𝕙𝕠𝕠𝕤𝕖 𝟛 𝕔𝕠𝕞 𝕞 𝕒𝕟𝕕𝕤:";
	std::cout << std::endl << std::endl;
	std::cout << "\t.𝐀𝐃𝐃" << std::endl << "\t.𝐒𝐄𝐀𝐑𝐂𝐇" << std::endl <<"\t.𝐄𝐗𝐈𝐓";
	std::cout << std::endl << std::endl;
	std::cout << "𝕎 𝕙𝕚𝕔𝕙 𝕠𝕟𝕖 𝕕𝕠 𝕪𝕠𝕦 𝕨𝕒𝕟𝕥 𝕥𝕠 𝕔𝕙𝕠𝕠𝕤𝕖 ?" << std::endl << ">";
}

/*
**	Destructeur
*/
Phonebook::~Phonebook() {
}

/*
**	Récupère l'input de l'entrée standard et appel la fonction adéquate
*/
bool	Phonebook::get_cmd() {
	std::string	cmd;

	if (!std::getline(std::cin, cmd)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (cmd == "add" || cmd == "ADD" || cmd == "Add")
		this->_add_cmd();
	else if (cmd == "search" || cmd == "SEARCH" || cmd == "Search")
		this->_search_cmd();
	else if (cmd == "exit" || cmd == "EXIT" || cmd == "Exit")
		return (this->_exit_cmd());
	else
		this->_wrong_cmd();
	return (true);
}

/*
**	Affiche sur la sortie standard un message d'erreur
*/
void	Phonebook::_wrong_cmd() const {
	std::cout << std::endl << "(っ◔◡◔)っ: 𝕊𝕠𝕣𝕣𝕪, 𝕪𝕠𝕦𝕣 𝕣𝕖𝕢𝕦𝕖𝕤𝕥 𝕒𝕣𝕖𝕟'𝕥 \
𝕧𝕒𝕝𝕚𝕕. 𝕐𝕠𝕦 𝕔𝕒𝕟 𝕔𝕙𝕠𝕠𝕤𝕖 𝟛 𝕔𝕠𝕞 𝕞 𝕒𝕟𝕕𝕤:" << std::endl << std::endl;
	std::cout << "\t.𝐀𝐃𝐃" << std::endl << "\t.𝐒𝐄𝐀𝐑𝐂𝐇" << std::endl <<"\t.𝐄𝐗𝐈𝐓";
	std::cout << std::endl << std::endl;
	std::cout << "𝕎 𝕙𝕚𝕔𝕙 𝕠𝕟𝕖 𝕕𝕠 𝕪𝕠𝕦 𝕨𝕒𝕟𝕥 𝕥𝕠 𝕔𝕙𝕠𝕠𝕤𝕖 ?" << std::endl << ">";
}

/*
**	Affiche la demande de la nouvelle commande et renvoi true
*/
bool	Phonebook::_next_request() const {
	std::cout << std::endl << "(っ◔◡◔)っ: 𝕎 𝕙𝕒𝕥'𝕤 𝕪𝕠𝕦𝕣 𝕟𝕖𝕩𝕥 𝕣𝕖𝕢𝕦𝕖𝕤𝕥 ?";
	std::cout << std::endl << ">";
	return (true);
}

/*
**	Ajoute first name au string data
*/
bool	Phonebook::_add_first_name(std::string *data) const {
	std::cout << std::endl << "𝕎 𝕙𝕒𝕥'𝕤 𝕙𝕚𝕤 𝕗𝕚𝕣𝕤𝕥 𝕟𝕒𝕞 𝕖 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝕊𝕠𝕣𝕣𝕪 𝕓𝕦𝕥 𝕪𝕠𝕦 𝕞 𝕦𝕤𝕥 𝕤𝕖𝕥 𝕒 𝕗𝕚𝕣𝕤𝕥 𝕟𝕒𝕞 𝕖";
		this->_add_first_name(data);
	}
	return (true);
}

/*
**	Ajoute last name au string data
*/
bool	Phonebook::_add_last_name(std::string *data) const {
	std::cout << std::endl << "𝕎 𝕙𝕒𝕥'𝕤 𝕙𝕚𝕤 𝕝𝕒𝕤𝕥 𝕟𝕒𝕞 𝕖 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝕊𝕠𝕣𝕣𝕪 𝕓𝕦𝕥 𝕪𝕠𝕦 𝕞 𝕦𝕤𝕥 𝕤𝕖𝕥 𝕒 𝕝𝕒𝕤𝕥 𝕟𝕒𝕞 𝕖.";
		this->_add_last_name(data);
	}
	return (true);
}

/*
**	Ajoute nickname au string data
*/
bool	Phonebook::_add_nickname(std::string *data) const {
	std::cout << std::endl << "𝕎 𝕙𝕒𝕥'𝕤 𝕙𝕚𝕤 𝕟𝕚𝕔𝕜𝕟𝕒𝕞 𝕖 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝕊𝕠𝕣𝕣𝕪 𝕓𝕦𝕥 𝕪𝕠𝕦 𝕞 𝕦𝕤𝕥 𝕤𝕖𝕥 𝕒 𝕟𝕚𝕔𝕜𝕟𝕒𝕞 𝕖.";
		this->_add_nickname(data);
	}
	return (true);
}

/*
**	Ajoute phone number au string data
*/
bool	Phonebook::_add_phone_number(std::string *data) const {
	std::cout << std::endl << "𝕎 𝕙𝕒𝕥'𝕤 𝕙𝕚𝕤 𝕡𝕙𝕠𝕟𝕖 𝕟𝕦𝕞 𝕓𝕖𝕣 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝕊𝕠𝕣𝕣𝕪 𝕓𝕦𝕥 𝕪𝕠𝕦 𝕞 𝕦𝕤𝕥 𝕤𝕖𝕥 𝕒 𝕡𝕙𝕠𝕟𝕖 𝕟𝕦𝕞 𝕓𝕖𝕣.";
		this->_add_phone_number(data);
	}
	return (true);
}

/*
**	Ajoute darkest secret au string data
*/
bool	Phonebook::_add_darkest_secret(std::string *data) const {
	std::cout << std::endl << "𝕎 𝕙𝕒𝕥'𝕤 𝕙𝕚𝕤 𝕕𝕒𝕣𝕜𝕖𝕤𝕥 𝕤𝕖𝕔𝕣𝕖𝕥 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝕊𝕠𝕣𝕣𝕪 𝕓𝕦𝕥 𝕪𝕠𝕦 𝕞 𝕦𝕤𝕥 𝕤𝕖𝕥 𝕒 𝕕𝕒𝕣𝕜𝕖𝕤𝕥 𝕤𝕖𝕔𝕣𝕖𝕥.";
		this->_add_darkest_secret(data);
	}
	return (true);
}

/*
** Commande ADD, qui ajoute un contact
*/
bool	Phonebook::_add_cmd() {
	if (this->index == MAX_SIZE) {
		if (this->scd_index == MAX_SIZE - 1)
			this->scd_index = -1;
		this->scd_index++;
	}
	else
		this->scd_index = this->index;
	std::string	data[5];
	std::cout << std::endl << "(っ◔◡◔)っ: ";
	if (!this->_add_first_name(&data[0]) || !this->_add_last_name(&data[1])
		|| !this->_add_nickname(&data[2]) || !this->_add_phone_number(&data[3])
		|| !this->_add_darkest_secret(&data[4]))
		return (false);
	this->contact[this->scd_index] = Contact(data);
	if (this->index != MAX_SIZE)
		this->index++;
	return (this->_next_request());
}

/*
**	Commande SEARCH, qui cherche un contact
*/
bool	Phonebook::_search_cmd() {
	if (!this->index) {
		std::cout << std::endl << "(س ͠° ͟ʖ ͡°)س: 𝕔𝕒𝕟𝕟𝕠𝕥 𝕤𝕖𝕒𝕣𝕔𝕙 𝕗𝕠𝕣 𝕒 𝕔𝕠𝕟𝕥𝕒𝕔𝕥 𝕚𝕗 𝕙𝕖'𝕤 𝕟𝕠𝕥 𝕒𝕕𝕕𝕖𝕕.";
		std::cout << std::endl;
		return (this->_next_request());
	}
	this->contact->print_contacts(this->index, this->contact);
	if (!this->contact->print_infos(this->index, this->contact))
		return (false);
	return (this->_next_request());
}

/*
**	Commande EXIT, qui quitte le programme
*/
bool	Phonebook::_exit_cmd() const {
	std::cout << std::endl << "( ＾◡＾)っ: 𝕀𝕥 𝕨𝕒𝕤 𝕒 𝕡𝕝𝕖𝕒𝕤𝕦𝕣𝕖. 𝕊𝕖𝕖 𝕪𝕠𝕦 ! 💗" << std::endl;
	return (false);
}

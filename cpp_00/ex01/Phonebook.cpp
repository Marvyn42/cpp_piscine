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
	std::cout << "\\(^β^)/: βπ π€ππ£. ππ π¦ πππ πππ π π€π π ππ π π ππππ€:";
	std::cout << std::endl << std::endl;
	std::cout << "\t.πππ" << std::endl << "\t.ππππππ" << std::endl <<"\t.ππππ";
	std::cout << std::endl << std::endl;
	std::cout << "π ππππ π ππ ππ  πͺπ π¦ π¨πππ₯ π₯π  πππ π π€π ?" << std::endl << ">";
}

/*
**	Destructeur
*/
Phonebook::~Phonebook() {
}

/*
**	RΓ©cupΓ¨re l'input de l'entrΓ©e standard et appel la fonction adΓ©quate
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
	std::cout << std::endl << "(γ£ββ‘β)γ£: ππ π£π£πͺ, πͺπ π¦π£ π£ππ’π¦ππ€π₯ ππ£ππ'π₯ \
π§ππππ. ππ π¦ πππ πππ π π€π π ππ π π ππππ€:" << std::endl << std::endl;
	std::cout << "\t.πππ" << std::endl << "\t.ππππππ" << std::endl <<"\t.ππππ";
	std::cout << std::endl << std::endl;
	std::cout << "π ππππ π ππ ππ  πͺπ π¦ π¨πππ₯ π₯π  πππ π π€π ?" << std::endl << ">";
}

/*
**	Affiche la demande de la nouvelle commande et renvoi true
*/
bool	Phonebook::_next_request() const {
	std::cout << std::endl << "(γ£ββ‘β)γ£: π πππ₯'π€ πͺπ π¦π£ πππ©π₯ π£ππ’π¦ππ€π₯ ?";
	std::cout << std::endl << ">";
	return (true);
}

/*
**	Ajoute first name au string data
*/
bool	Phonebook::_add_first_name(std::string *data) const {
	std::cout << std::endl << "π πππ₯'π€ πππ€ πππ£π€π₯ πππ π ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "Β―\\_ΰ² _ΰ² _/Β―: ππ π£π£πͺ ππ¦π₯ πͺπ π¦ π π¦π€π₯ π€ππ₯ π πππ£π€π₯ πππ π";
		this->_add_first_name(data);
	}
	return (true);
}

/*
**	Ajoute last name au string data
*/
bool	Phonebook::_add_last_name(std::string *data) const {
	std::cout << std::endl << "π πππ₯'π€ πππ€ πππ€π₯ πππ π ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "Β―\\_ΰ² _ΰ² _/Β―: ππ π£π£πͺ ππ¦π₯ πͺπ π¦ π π¦π€π₯ π€ππ₯ π πππ€π₯ πππ π.";
		this->_add_last_name(data);
	}
	return (true);
}

/*
**	Ajoute nickname au string data
*/
bool	Phonebook::_add_nickname(std::string *data) const {
	std::cout << std::endl << "π πππ₯'π€ πππ€ πππππππ π ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "Β―\\_ΰ² _ΰ² _/Β―: ππ π£π£πͺ ππ¦π₯ πͺπ π¦ π π¦π€π₯ π€ππ₯ π πππππππ π.";
		this->_add_nickname(data);
	}
	return (true);
}

/*
**	Ajoute phone number au string data
*/
bool	Phonebook::_add_phone_number(std::string *data) const {
	std::cout << std::endl << "π πππ₯'π€ πππ€ π‘ππ ππ ππ¦π πππ£ ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "Β―\\_ΰ² _ΰ² _/Β―: ππ π£π£πͺ ππ¦π₯ πͺπ π¦ π π¦π€π₯ π€ππ₯ π π‘ππ ππ ππ¦π πππ£.";
		this->_add_phone_number(data);
	}
	return (true);
}

/*
**	Ajoute darkest secret au string data
*/
bool	Phonebook::_add_darkest_secret(std::string *data) const {
	std::cout << std::endl << "π πππ₯'π€ πππ€ πππ£πππ€π₯ π€πππ£ππ₯ ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "Β―\\_ΰ² _ΰ² _/Β―: ππ π£π£πͺ ππ¦π₯ πͺπ π¦ π π¦π€π₯ π€ππ₯ π πππ£πππ€π₯ π€πππ£ππ₯.";
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
	std::cout << std::endl << "(γ£ββ‘β)γ£: ";
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
		std::cout << std::endl << "(Ψ³ Ν Β° ΝΚ Ν‘Β°)Ψ³: πππππ π₯ π€πππ£ππ ππ π£ π ππ ππ₯πππ₯ ππ ππ'π€ ππ π₯ πππππ.";
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
	std::cout << std::endl << "( οΌΎβ‘οΌΎ)γ£: ππ₯ π¨ππ€ π π‘ππππ€π¦π£π. πππ πͺπ π¦ ! π" << std::endl;
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:17:15 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/13 23:34:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "phone_bot.h"

Phonebook::Phonebook() {
	this->index = 0;
	std::cout << "\\(^◇^)/: 𝐻𝒾 𝓈𝒾𝓇. 𝒴𝑜𝓊 𝒸𝒶𝓃 𝒸𝒽𝑜𝓈𝑒 𝟥 𝒸𝑜𝓂 𝓂 𝒶𝓃𝒹𝓈:" << std::endl << std::endl;
	std::cout << "\t.𝐀𝐃𝐃" << std::endl << "\t.𝐒𝐄𝐀𝐑𝐂𝐇" << std::endl <<"\t.𝐄𝐗𝐈𝐓" << std::endl << std::endl;
	std::cout << "𝒲 𝒽𝒾𝒸𝒽 𝑜𝓃𝑒 𝒹𝑜 𝓎𝑜𝓊 𝓌 𝒶𝓃𝓉 𝓉𝑜 𝒸𝒽𝑜𝑜𝓈𝑒 ?" << std::endl << ">";
}

Phonebook::~Phonebook() {
}

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

void	Phonebook::_wrong_cmd() {
	std::cout << std::endl << "(っ◔◡◔)っ: 𝒮𝑜𝓇𝓇𝓎, 𝓎𝑜𝓊𝓇 𝓇𝑒𝓆𝓊𝑒𝓈𝓉 𝒶𝓇𝑒𝓃'𝓉 \
𝓋𝒶𝓁𝒾𝒹. 𝒴𝑜𝓊 𝒸𝒶𝓃 𝒸𝒽𝑜𝓈𝑒 𝟥 𝒸𝑜𝓂 𝓂 𝒶𝓃𝒹𝓈:" << std::endl << std::endl;
	std::cout << "\t.𝐀𝐃𝐃" << std::endl << "\t.𝐒𝐄𝐀𝐑𝐂𝐇" << std::endl <<"\t.𝐄𝐗𝐈𝐓" << std::endl << std::endl;
	std::cout << "𝒲 𝒽𝒾𝒸𝒽 𝑜𝓃𝑒 𝒹𝑜 𝓎𝑜𝓊 𝓌 𝒶𝓃𝓉 𝓉𝑜 𝒸𝒽𝑜𝑜𝓈𝑒 ?" << std::endl << ">";
}

bool	Phonebook::_next_request() {
	std::cout << std::endl << "(っ◔◡◔)っ: 𝒲𝒽𝒶𝓉'𝓈 𝓎𝑜𝓊𝓇 𝓃𝑒𝓍𝓉 𝓇𝑒𝓆𝓊𝑒𝓈𝓉 ?" << std::endl << ">";
	return (true);
}

bool	Phonebook::_add_first_name(std::string *data) {
	std::cout << std::endl << "𝒲𝒽𝒶𝓉'𝓈 𝒽𝒾𝓈 𝒻𝒾𝓇𝓈𝓉 𝓃𝒶𝓂 𝑒 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝒮𝑜𝓇𝓇𝓎 𝒷𝓊𝓉 𝓎𝑜𝓊 𝓂 𝓊𝓈𝓉 𝓈𝑒𝓉 𝒶 𝒻𝒾𝓇𝓈𝓉 𝓃𝒶𝓂 𝑒.";
		this->_add_first_name(data);
	}
	return (true);
}

bool	Phonebook::_add_last_name(std::string *data) {
	std::cout << std::endl << "𝒲𝒽𝒶𝓉'𝓈 𝒽𝒾𝓈 𝓁𝒶𝓈𝓉 𝓃𝒶𝓂 𝑒 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝒮𝑜𝓇𝓇𝓎 𝒷𝓊𝓉 𝓎𝑜𝓊 𝓂 𝓊𝓈𝓉 𝓈𝑒𝓉 𝒶 𝓁𝒶𝓈𝓉 𝓃𝒶𝓂 𝑒.";
		this->_add_last_name(data);
	}
	return (true);
}

bool	Phonebook::_add_nickname(std::string *data) {
	std::cout << std::endl << "𝒲𝒽𝒶𝓉'𝓈 𝒽𝒾𝓈 𝓃𝒾𝒸𝓀𝓃𝒶𝓂 𝑒 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝒮𝑜𝓇𝓇𝓎 𝒷𝓊𝓉 𝓎𝑜𝓊 𝓂 𝓊𝓈𝓉 𝓈𝑒𝓉 𝒶 𝓃𝒾𝒸𝓀𝓃𝒶𝓂 𝑒.";
		this->_add_nickname(data);
	}
	return (true);
}

bool	Phonebook::_add_phone_number(std::string *data) {
	std::cout << std::endl << "𝒲𝒽𝒶𝓉'𝓈 𝒽𝒾𝓈 𝓅𝒽𝑜𝓃𝑒 𝓃𝓊𝓂 𝒷𝑒𝓇 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝒮𝑜𝓇𝓇𝓎 𝒷𝓊𝓉 𝓎𝑜𝓊 𝓂 𝓊𝓈𝓉 𝓈𝑒𝓉 𝒶 𝓅𝒽𝑜𝓃𝑒 𝓃𝓊𝓂 𝒷𝑒𝓇.";
		this->_add_phone_number(data);
	}
	return (true);
}

bool	Phonebook::_add_darkest_secret(std::string *data) {
	std::cout << std::endl << "𝒲𝒽𝒶𝓉'𝓈 𝒽𝒾𝓈 𝒹𝒶𝓇𝓀𝑒𝓈𝓉 𝓈𝑒𝒸𝓇𝑒𝓉 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	return (true);
}

bool	Phonebook::_add_cmd() {
	if (this->index == 8) {
		std::cout << std::endl << "(⇀‸↼‶): 𝒯𝒽𝑒 𝓅𝒽𝑜𝓃𝑒 𝒷𝑜𝑜𝓀 𝒾𝓈 𝒻𝓊𝓁𝓁, \
𝓎𝑜𝓊 𝓇𝑒𝒶𝒸𝒽𝑒𝒹 𝓉𝒽𝑒 𝓂𝒶𝓍𝒾𝓂 𝓊𝓂 𝓈𝒾𝓏𝑒 𝑜𝒻 𝓈𝒾𝓏𝑒 𝑜𝒻 𝟪. 𝒩𝑜𝓉𝒽𝒾𝓃𝑔 𝑒𝓁𝓈𝑒 𝒸𝒶𝓃 𝒷𝑒 𝒶𝒹𝒹𝑒𝒹." << std::endl;
		return (this->_next_request());
	}
	std::string	data[5];
	std::cout << std::endl << "(っ◔◡◔)っ: ";
	if (!this->_add_first_name(&data[0]) || !this->_add_last_name(&data[1])
		|| !this->_add_nickname(&data[2]) || !this->_add_phone_number(&data[3])
		|| !this->_add_darkest_secret(&data[4]))
		return (false);
	this->contact[this->index] = Contact(data);
	this->index++;
	return (this->_next_request());
}

bool	Phonebook::_search_cmd() {
	if (!this->index) {
		std::cout << std::endl << "(س ͠° ͟ʖ ͡°)س: 𝒸𝒶𝓃𝓃𝑜𝓉 𝓈𝑒𝒶𝓇𝒸𝒽 𝒻𝑜𝓇 𝒶 𝒸𝑜𝓃𝓉𝒶𝒸𝓉 𝒾𝒻 𝒽𝑒'𝓈 𝓃𝑜𝓉 𝒶𝒹𝒹𝑒𝒹" << std::endl;
		return (this->_next_request());
	}
	this->contact->print_contacts(this->index, this->contact);
	if (!this->contact->print_infos(this->index, this->contact))
		return (false);
	return (this->_next_request());
}

bool	Phonebook::_exit_cmd() {
	std::cout << std::endl << "( ＾◡＾)っ: 𝐼𝓉 𝓌 𝒶𝓈 𝒶 𝓅𝓁𝑒𝒶𝓈𝓊𝓇𝑒. 𝒮𝑒𝑒 𝓎𝑜𝓊 ! 💗" << std::endl;
	return (false);
}

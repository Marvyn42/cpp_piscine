/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:17:15 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/13 03:29:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->index = 0;
	std::cout << "\\(^◇^)/: 𝓗𝓲 𝓼𝓲𝓻. 𝓨𝓸𝓾 𝓬𝓪𝓷 𝓬𝓱𝓸𝓼𝓮 3 𝓬𝓸𝓶𝓶𝓪𝓷𝓭𝓼:" << std::endl << std::endl;
	std::cout << "\t.𝓐𝓓𝓓" << std::endl << "\t.𝓢𝓔𝓐𝓡𝓒𝓗" << std::endl <<"\t.𝓔𝓧𝓘𝓣" << std::endl << std::endl;
	std::cout << "𝓦𝓱𝓲𝓬𝓱 𝓸𝓷𝓮 𝓭𝓸 𝔂𝓸𝓾 𝔀𝓪𝓷𝓽 𝓽𝓸 𝓬𝓱𝓸𝓸𝓼𝓮 ?" << std::endl << ">";
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
	std::cout << std::endl << "(っ◔◡◔)っ: 𝓢𝓸𝓻𝓻𝔂, 𝔂𝓸𝓾𝓻 𝓻𝓮𝓺𝓾𝓮𝓼𝓽 𝓪𝓻𝓮𝓷'𝓽 \
𝓿𝓪𝓵𝓲𝓭. 𝓨𝓸𝓾 𝓬𝓪𝓷 𝓬𝓱𝓸𝓼𝓮 3 𝓬𝓸𝓶𝓶𝓪𝓷𝓭𝓼:" << std::endl << std::endl;
	std::cout << "\t.𝓐𝓓𝓓" << std::endl << "\t.𝓢𝓔𝓐𝓡𝓒𝓗" << std::endl <<"\t.𝓔𝓧𝓘𝓣" << std::endl << std::endl;
	std::cout << "𝓦𝓱𝓲𝓬𝓱 𝓸𝓷𝓮 𝓭𝓸 𝔂𝓸𝓾 𝔀𝓪𝓷𝓽 𝓽𝓸 𝓬𝓱𝓸𝓸𝓼𝓮 ?" << std::endl << ">";
}

bool	Phonebook::_next_request() {
	std::cout << std::endl << "(っ◔◡◔)っ: 𝓦𝓱𝓪𝓽'𝓼 𝔂𝓸𝓾𝓻 𝓷𝓮𝔁𝓽 𝓻𝓮𝓺𝓾𝓮𝓼𝓽 ?" << std::endl << ">";
	return (true);
}

bool	Phonebook::_add_first_name(std::string *data) {
	std::cout << std::endl << "𝓦𝓱𝓪𝓽'𝓼 𝓱𝓲𝓼 𝓯𝓲𝓻𝓼𝓽 𝓷𝓪𝓶𝓮 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝓢𝓸𝓻𝓻𝔂 𝓫𝓾𝓽 𝔂𝓸𝓾 𝓶𝓾𝓼𝓽 𝓼𝓮𝓽 𝓪 𝓯𝓲𝓻𝓼𝓽 𝓷𝓪𝓶𝓮.";
		this->_add_first_name(data);
	}
	return (true);
}

bool	Phonebook::_add_last_name(std::string *data) {
	std::cout << std::endl << "𝓦𝓱𝓪𝓽'𝓼 𝓱𝓲𝓼 𝓵𝓪𝓼𝓽 𝓷𝓪𝓶𝓮 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝓢𝓸𝓻𝓻𝔂 𝓫𝓾𝓽 𝔂𝓸𝓾 𝓶𝓾𝓼𝓽 𝓼𝓮𝓽 𝓪 𝓵𝓪𝓼𝓽 𝓷𝓪𝓶𝓮.";
		this->_add_last_name(data);
	}
	return (true);
}

bool	Phonebook::_add_nickname(std::string *data) {
	std::cout << std::endl << "𝓦𝓱𝓪𝓽'𝓼 𝓱𝓲𝓼 𝓷𝓲𝓬𝓴𝓮𝓷𝓪𝓶𝓮 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝓢𝓸𝓻𝓻𝔂 𝓫𝓾𝓽 𝔂𝓸𝓾 𝓶𝓾𝓼𝓽 𝓼𝓮𝓽 𝓪 𝓷𝓲𝓬𝓴𝓮𝓷𝓪𝓶𝓮.";
		this->_add_nickname(data);
	}
	return (true);
}

bool	Phonebook::_add_phone_number(std::string *data) {
	std::cout << std::endl << "𝓦𝓱𝓪𝓽'𝓼 𝓱𝓲𝓼 𝓹𝓱𝓸𝓷𝓮 𝓷𝓾𝓶𝓫𝓮𝓻 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	if (!(*data).length()) {
		std::cout << std::endl << "¯\\_ಠ_ಠ_/¯: 𝓢𝓸𝓻𝓻𝔂 𝓫𝓾𝓽 𝔂𝓸𝓾 𝓶𝓾𝓼𝓽 𝓼𝓮𝓽 𝓪 𝓹𝓱𝓸𝓷𝓮 𝓷𝓾𝓶𝓫𝓮𝓻.";
		this->_add_phone_number(data);
	}
	return (true);
}

bool	Phonebook::_add_darkest_secret(std::string *data) {
	std::cout << std::endl << "𝓦𝓱𝓪𝓽'𝓼 𝓱𝓲𝓼 𝓭𝓪𝓻𝓴𝓮𝓼𝓽 𝓼𝓮𝓬𝓻𝓮𝓽 ?" << std::endl << ">";
	if (!std::getline(std::cin, *data)) {
		std::cerr << "Error getline. Exit." << std::endl;
		return (false);
	}
	return (true);
}

bool	Phonebook::_add_cmd() {
	if (this->index == 8) {
		std::cout << std::endl << "(⇀‸↼‶): 𝓣𝓱𝓮 𝓹𝓱𝓸𝓷𝓮 𝓫𝓸𝓸𝓴 𝓲𝓼 𝓯𝓾𝓵𝓵, \
𝔂𝓸𝓾 𝓻𝓮𝓪𝓬𝓱𝓮𝓭 𝓽𝓱𝓮 𝓶𝓪𝔁𝓲𝓶𝓾𝓶 𝓼𝓲𝔃𝓮 𝓸𝓯 8. 𝓝𝓸𝓽𝓱𝓲𝓷𝓰 𝓮𝓵𝓼𝓮 𝓬𝓪𝓷 𝓫𝓮 𝓪𝓭𝓭𝓮𝓭." << std::endl;
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
		std::cout << std::endl << "(س ͠° ͟ʖ ͡°)س: 𝓒𝓪𝓷𝓷𝓸𝓽 𝓼𝓮𝓪𝓻𝓬𝓱 𝓬𝓸𝓷𝓽𝓪𝓬𝓽 𝓲𝓯 𝓲𝓼 𝓷𝓸𝓽 𝓪𝓭𝓭𝓮𝓭" << std::endl;
		return (this->_next_request());
	}
	std::cout << "|index-----|first name|last name-|nickname--|" << std::endl;
	this->contact->print_contacts(this->index);
	return (this->_next_request());
}

bool	Phonebook::_exit_cmd() {
	std::cout << std::endl << "( ＾◡＾)っ: 𝓘𝓽 𝔀 𝓪𝓼 𝓪 𝓹𝓵𝓮𝓪𝓼𝓾𝓻𝓮. 𝓢𝓮𝓮 𝔂𝓸𝓾 ! 💗" << std::endl;
	return (false);
}

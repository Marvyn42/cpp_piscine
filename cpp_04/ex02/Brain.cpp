/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:42:35 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/03 01:52:48 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Brain::Brain() {
	std::cout << "Default Brain constructor" << std::endl;
	this->ideas[0] = "No idea...";
}

Brain::Brain(Brain const & cpy) {
	*this = cpy;
	std::cout << "Cpy Brain constructor" << std::endl;
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

Brain::~Brain() {
	std::cout << "Default Brain destructor" << std::endl;
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

Brain & Brain::operator=(Brain const &ref) {
	std::cout << "Surcharge d'opérateur Brain" << std::endl;
	unsigned int i = 0;
	for (; ref.getIdeas(i).size(); i++) {
		this->ideas[i] = ref.getIdeas(i);
	}
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	Brain::printIdeas() const {
	for (unsigned int i = 0; this->ideas[i].size(); i++) {
		std::cout << "idea[" << i << "] = " << this->ideas[i] << std::endl;
	}
}

std::string	Brain::getIdeas(unsigned int index) const {
	return (this->ideas[index]);
}

void	Brain::setIdeas(std::string idea) {
	unsigned int i = 0;
	while (this->ideas[i].size()) 
		i++;
	this->ideas[i] = idea;
}

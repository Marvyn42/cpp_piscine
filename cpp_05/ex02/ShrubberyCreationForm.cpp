/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:53:16 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/12 14:20:17 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : 
	AForm("Shrubbery", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy) : AForm(cpy) {
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref) {
	(void)ref;
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->get_execGrade())
		throw AForm::GradeTooLowException();

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream os(filename.c_str());

	os << "           &&& &&  & &&" << std::endl
			<< "      && &\\/&\\|& ()|/ @, &&" << std::endl
			<< "      &\\/(/&/&||/& /_/)_&/_&" << std::endl
			<< "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl
			<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl
			<< "&&   && & &| &| /& & % ()& /&&" << std::endl
			<< " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl
			<< "     &&     \\|||/" << std::endl
			<< "             |||" << std::endl
			<< "             |||" << std::endl
			<< "             |||" << std::endl
			<< "       , -=-~  .-^- _" << std::endl
			<< "              `" << std::endl;
	os.close();
}

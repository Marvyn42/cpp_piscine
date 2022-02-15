/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:24:27 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/15 16:05:27 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const & cpy);
		virtual ~Intern();

		Intern & operator=(Intern const & ref);

		AForm	*makeForm(std::string const &form_name, std::string const &target);
	private:
		AForm	*_form;

		AForm	*makeShrubberyCreation(std::string const & target);
		AForm	*makeRobotomyRequest(std::string const & target);
		AForm	*makePresidentialPardon(std::string const & target);
};



#endif

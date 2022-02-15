/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:32:29 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/14 01:45:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(std::string const & name = "NoName", uint32_t signeGrade = MIN_GRADE,
			uint32_t execGrade = MIN_GRADE, std::string const & target = "NoName");
		AForm(AForm const & cpy);

		virtual ~AForm();

		AForm & operator=(AForm const & ref);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Grade too high.");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Grade too low.");
				}
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return ("form is unsigned, can not execute it.");
				}
		};

		virtual void	execute(Bureaucrat const & executor) const = 0;

		void	beSigned(Bureaucrat const & ref);

		std::string	getName() const;
		std::string	getTarget() const;
		bool		isSigned() const;
		uint32_t	get_signeGrade() const;
		uint32_t	get_execGrade() const;
		
	private:
		const std::string	_name;
		bool				_signe;
		const uint32_t		_signeGrade;
		const uint32_t		_execGrade;
		const std::string	_target;
};

std::ostream & operator<<(std::ostream & os, AForm & ref);


#endif

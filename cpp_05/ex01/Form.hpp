/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:32:29 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/11 03:43:14 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	public:
		Form(std::string const & name = "NoName",
			uint32_t signeGrade = MIN_GRADE, uint32_t execGrade = MIN_GRADE);
		Form(Form const & cpy);

		virtual ~Form();

		Form & operator=(Form const & ref);

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

		void	beSigned(Bureaucrat const & ref);

		std::string	getName() const;
		bool		isSigned() const;
		uint32_t	get_signeGrade() const;
		uint32_t	get_execGrade() const;
		
	private:
		const std::string	_name;
		bool				_signe;
		const uint32_t		_signeGrade;
		const uint32_t		_execGrade;
};

std::ostream & operator<<(std::ostream & os, Form & ref);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:46:27 by mamaquig          #+#    #+#             */
/*   Updated: 2022/03/12 14:26:32 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>
# include <stdint.h>
# include <exception>
# include <fstream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(std::string const & name = "NoName", uint32_t grade = MIN_GRADE);
		Bureaucrat(Bureaucrat const & cpy);

		virtual ~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & ref);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		void	executeForm(AForm const & form) const;

		void	UpGrade();
		void	DownGrade();
		void	signForm(AForm & form);

		std::string	getName() const;
		uint32_t	getGrade() const;
		
	private:
		const std::string	_name;
		uint32_t			_grade;
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & ref);

#endif

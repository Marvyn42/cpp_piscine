/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:50:56 by mamaquig          #+#    #+#             */
/*   Updated: 2022/02/14 01:40:42 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENT_HPP
# define PRESIDENT_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & cpy);

		virtual ~PresidentialPardonForm();

		PresidentialPardonForm & operator=(PresidentialPardonForm const & ref);

		virtual void	execute(Bureaucrat const & executor) const;
};

#endif

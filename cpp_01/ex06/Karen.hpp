/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:12:44 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/23 22:07:21 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <cstdlib>

class Karen
{
	public:
		Karen();
		~Karen();

		void	complain(std::string level);
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();
};

#endif

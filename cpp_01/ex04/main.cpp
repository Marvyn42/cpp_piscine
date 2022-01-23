/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:53:29 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/23 04:47:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.h"

void	ft_replace(std::string &tmp, std::string s1, std::string s2) {
	for (size_t pos = tmp.find(s1); pos < tmp.size(); pos = tmp.find(s1, pos+1)) {
		tmp.erase(pos, s1.size());
		tmp.insert(pos, s2);
	}
}


bool	checkArgs(std::ifstream &ifs, std::string s1, std::string s2) {
	if (s1.empty() || s2.empty() || !ifs) {
		if (!ifs)
			std::cerr << "filestream doesn't exist or haven't permissions." << std::endl;
		else
			std::cerr << "S1 or S2 should not be empty." << std::endl;
		return (false);
	}
	return (true);
}

void	filenameReplace(std::string &filename) {
	size_t pos = filename.find_last_of('.');
	filename = filename.substr(0, pos) + ".replace";
}

int		main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Not enough arguments" << std::endl;
		std::cerr << "Usage:" << std::endl << "./replace [filename] [s1] [s2]" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream		ifs(av[1]);
	std::string			filename = av[1];
	std::string const	s1 = av[2];
	std::string const	s2 = av[3];
	std::string			tmp;
	
	if (!checkArgs(ifs, s1, s2))
		return (EXIT_FAILURE);
	filenameReplace(filename);
	std::ofstream ofs(filename.c_str());
	while (std::getline(ifs, tmp)) {
		ft_replace(tmp, s1, s2);
		ofs << tmp << std::endl;
	}
	ifs.close();
	ofs.close();
	return (EXIT_SUCCESS);
}

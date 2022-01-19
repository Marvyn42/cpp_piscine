/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:24:29 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/19 16:43:28 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*
**	Initialisation des variables statics
*/
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

/*
**	Constructeur par défaut
*/
Account::Account( void ) {
}

/*
**	Constructeur avec initialisation de données
*/
Account::Account( int initial_deposit ) :	_accountIndex(_nbAccounts++),
											_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0)	{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_totalAmount += _amount;
}

/*
**	Destructeur par défaut
*/
Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

/*
**	Retourne le nb total d'accounts
*/
int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

/*
**	Retourne le nb total d'amounts
*/
int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

/*
**	Retourne le nb total de deposits
*/
int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

/*
**	Retourne le nb total de Withdrawals
*/
int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

/*
**	Affiche les informations globales
*/
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

/*
**	Affiche l'horodatage format: ANNÉE/MOIS/JOURS_HEURES/MINUTES/SECONDES
*/
void	Account::_displayTimestamp( void ) {
	time_t		tt;
	struct tm	*dt;
	char		s[16];

	tt = time(NULL);
	dt = localtime(&tt);
	strftime(s, 16, "%Y%m%d_%H%M%S", dt);
	std::cout << "[" << s << "]" << " ";
}

/*
**	Créer un dépôt sur le compte
*/
void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposits:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << checkAmount()<< ";";
	_nbDeposits += 1;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
}

/*
**	Créer un retrait sur le compte
*/
bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "withdrawal:";
	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	std::cout << "amount:" << checkAmount() << ";";
	_nbWithdrawals += 1;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	return (true);
}

/*
**	Retourne le montant
*/
int		Account::checkAmount( void ) const {
	return (_amount);
}

/*
**	Affiche le statut du compte
*/
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

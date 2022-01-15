/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:24:29 by mamaquig          #+#    #+#             */
/*   Updated: 2022/01/14 23:33:53 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( void ) {
	//Initialiser l'affichage
	//std::cout << [horodatage] << " index:" << 
}

Account::Account( int initial_deposit ) {
}

Account::~Account( void ) {
	//afficher:
	//[horodatage] index;amount;closed
}

static int	getNbAccounts( void ) {
}

static int	getTotalAmount( void ) {
}

static int	getNbDeposits( void ) {
}

static int	getNbWithdrawals( void ) {
}

// displayAccountsInfos affichera:
// [horodatage] _nbAccounts;_totalAmount;_totalNbDeposits;_totalNbWithdrawals
static void	displayAccountsInfos( void ) {
}

static void	_displayTimestamp( void ) {
}

void	makeDeposit( int deposit ) {
}

bool	makeWithdrawal( int withdrawal ) {
}

int		checkAmount( void ) const {
}

void	displayStatus( void ) const {
}

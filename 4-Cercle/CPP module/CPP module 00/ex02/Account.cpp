/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:58:58 by armendes          #+#    #+#             */
/*   Updated: 2022/04/26 20:16:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( int initial_deposit )
{
	////
	return;
}

Account::~Account( void )
{
	return;
}

static int	Account::getNbAccounts( void )
{
	return (this->_nbAccounts);
}

static int	Account::getTotalAmount( void )
{
	return (this->_totalAmount);
}

static int	Account::getNbDeposits( void )
{
	return (this->_totalNbDeposits);
}

static int	Account::getNbWithdrawals( void )
{
	return (this->_totalNbWithdrawals);
}

static void	Account::displayAccountsInfos( void )
{
	std::cout << "index:" << this.getNbAccounts() << ";";
	std::cout << ""
}
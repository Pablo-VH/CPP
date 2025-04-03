/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:03:36 by pavicent          #+#    #+#             */
/*   Updated: 2025/04/03 13:04:11 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	std::cout << "getNbAccounts" << std::endl;
	return (_nbAccounts);
}

int	Account::getNbDeposits(void)
{
	std::cout << "getNbDeposits" << std::endl;
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	std::cout << "getNbWithdrawals" << std::endl;
	return (_totalNbWithdrawals);
}

int	Account::getTotalAmount(void)
{
	std::cout << "getTotalAmount" << std::endl;
	return (_totalAmount);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::checkAmount(void)const
{
	std::cout << "checkAmount" << std::endl;
	return(_totalAmount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals" << _nbWithdrawals << std::endl;
	return (true);
}

void	Account::makeDeposit(int deposit)
{
	int	pamount;

	pamount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << pamount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		timestamp;
	struct tm	*timeinfo;
	char		buffer[20];
	
	time(&timestamp);
	timeinfo = localtime(&timestamp);
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}

Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << initial_deposit << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

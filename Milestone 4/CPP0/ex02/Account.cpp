/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:30:43 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/24 16:33:58 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account:: _totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

Account::Account(void) {}

// constructor function
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";created" << std::endl;
}

// destructor function
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    std::cout << ";deposit:" << deposit
    << ";amount:" << _totalAmount
    << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount;

    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
    << "amount:" << _totalAmount
    << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *t = std::localtime(&now);

    std::cout << "[" << (t->tm_year + 1900)
    << std::setw(2) << std::setfill('0') << t->tm_mon + 1
    << std::setw(2) << std::setfill('0') << t->tm_mday << "_"
    << std::setw(2) << std::setfill('0') << t->tm_hour
    << std::setw(2) << std::setfill('0') << t->tm_min
    << std::setw(2) << std::setfill('0') << t->tm_sec
    << "]";
}

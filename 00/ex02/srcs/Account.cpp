#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	time_t		now;
	struct tm	*ts;
	char		buf[80];

	now = time(NULL);
	ts = localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", ts);
	std::cout << buf;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) :
		_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	this->_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created:" << std::endl;
	Account::_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

Account::Account(void)
{
	this->_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed:" << std::endl;	
}

Account::~Account( void )
{
	return;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount) {
		std::cout << "withdrawal:refused" << std::endl; return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout	<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_withdrawal:" << this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
    			<< "amount:" << this->_amount << ";"
    			<< "deposits:" << this->_nbDeposits << ";"
    			<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}
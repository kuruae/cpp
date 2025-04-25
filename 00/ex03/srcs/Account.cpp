#include "Account.hpp"

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	
}

Account::Account( int initial_deposit )
{
	Account::_nbAccounts++;
	this->_accountIndex = Account::_nbAccounts;
	makeDeposit(initial_deposit);
}

Account::~Account( void );

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{

}
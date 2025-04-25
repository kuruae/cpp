#pragma once

#include "Setup.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();	

private:
	Contact contacts[8];
	int		contactCount;
};
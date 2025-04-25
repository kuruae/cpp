#include "Setup.hpp"

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
}

PhoneBook::~PhoneBook()
{
	return;
}

void PhoneBook::addContact()
{
	Contact		contact;
	std::string	str;

	do {
		std::cout << "enter the First Name of the contact: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			eofExit();
	} while (str.empty());
	contact.setFirstName(str);
	str.clear();

	do {
		std::cout << "enter the Last Name of the contact: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			eofExit();
		} while (str.empty());
	contact.setLastName(str);
	str.clear();

	do {
		std::cout << "enter the Nickname of the contact: ";
		std::getline(std::cin, str);
	
		if (std::cin.eof())
			eofExit();
		} while (str.empty());
	contact.setNickname(str);
	str.clear();

	do {
		std::cout << "enter the Phone Number of the contact: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			eofExit();
		} while (str.empty());
	contact.setPhoneNumber(str);
	str.clear();

	do {
		std::cout << "enter the Darkest Secret of the contact: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			eofExit();
		} while (str.empty());
	contact.setDarkestSecret(str);
	str.clear();

	std::cout << GRN << "\nContact added successfully !\n" << END << std::endl;

	if (this->contactCount == 8) {
		for (int i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i + 1];
		this->contactCount = 7;
	}
	this->contacts[this->contactCount] = contact;
	this->contactCount++;
}

void	displayHeader()
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│   INDEX  │FIRST NAME│ LAST NAME│ NICKNAME │" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
}

static bool is_str_digit(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << RED "non numerical value\n" END;
			return false;
		}
	}
	return true;
}

void	PhoneBook::searchContact()
{
	if (this->contactCount == 0) {
		std::cout << RED << "No contacts in the phonebook yet!" << END << std::endl;
		return;
	}
	

	// header part ---------------------------------------------
	displayHeader();

	for (int i = 0; i < this->contactCount; i++) {
		std::cout << "│" << std::setw(10) << i << "│";

		if (this->contacts[i].getFirstName().length() > 10)
			std::cout << this->contacts[i].getFirstName().substr(0, 7) << "...|";
		else
			std::cout << std::setw(10) << this->contacts[i].getFirstName() << "|";

		if (this->contacts[i].getLastName().length() > 10)
			std::cout << this->contacts[i].getLastName().substr(0, 7) << "...|";
		else
			std::cout << std::setw(10) << this->contacts[i].getLastName() << "|";

		if (this->contacts[i].getNickname().length() > 10)
			std::cout << this->contacts[i].getNickname().substr(0, 7) << "...|";
		else
			std::cout << std::setw(10) << this->contacts[i].getNickname() << "|";

		std::cout << std::endl;
	}

	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;


	// input part ---------------------------------------------
	std::string input;
	int index;
	
	do
	{
		std::cout << "Enter the index of the contact to display (0-" 
				  << this->contactCount - 1 << "): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			eofExit();
	} while (input.empty() || !is_str_digit(input));
	
	index = atoi(input.c_str());
	if (index < 0 || index >= this->contactCount) {
		std::cout << RED << "Index out of range!" << END << std::endl;
		return;
	}

	std::cout << "\nCONTACT INFORMATION" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
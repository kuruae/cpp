#pragma once

#include "Setup.hpp"

class Contact {
public:
	Contact();
	~Contact();

	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickname(std::string nickname);
	void	setPhoneNumber(std::string phoneNumber);
	void	setDarkestSecret(std::string darkestSecret);

	std::string		getFirstName() const;
	std::string		getLastName() const;
	std::string		getNickname() const;
	std::string		getPhoneNumber() const;
	std::string		getDarkestSecret() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};
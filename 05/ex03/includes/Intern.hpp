#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

	AForm* makeForm(const str& formName, const str& target) const;

	class FormNotFoundException : public std::runtime_error {
	public:
		FormNotFoundException();
	};

private:
	AForm*	createShrubberyCreationForm(const str& target) const;
	AForm*	createRobotomyRequestForm(const str& target) const;
	AForm*	createPresidentialPardonForm(const str& target) const;
};
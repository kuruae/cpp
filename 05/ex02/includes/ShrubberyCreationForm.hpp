#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const str& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	void	execute(const Bureaucrat& executor) const;

private:
	str		_target;
	void	createShrubbery() const;
};
#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const str& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void	execute(const Bureaucrat& executor) const;
private:
	str		_target;
	void	pardon() const;
};

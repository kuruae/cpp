#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const str& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void	execute(const Bureaucrat& executor) const;
private:
	str		_target;
	void	robotomize() const;
};

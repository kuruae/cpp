#pragma once

#include <iostream>
#include <string>
#include <exception>	

typedef std::string str;

class Form
{
public:
	Form();
	Form(const str& name, const int gradeSign, const int gradeExec);
	Form(const Form& other);
	~Form();

	Form&	operator=(const Form& other);

	str		getName() const;
	int		getSignGrade() const;
	int		getExecGrade() const;
	bool	getSignedState() const;

	void	beSigned(const Bureaucrat* bureaucrat) const;

private:
	void	signForm(int grade) const;

	const str	_name;
	const int	_requieredSignGrade;
	const int	_requieredExecGrade;
	bool		_isSigned;

};

std::ostream& operator<<(std::ostream& os, const Form& form);
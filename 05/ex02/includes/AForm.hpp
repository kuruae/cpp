#pragma once

#include <iostream>
#include <string>
#include <exception>	

class Bureaucrat;

typedef std::string str;

class AForm
{
public:
	AForm();
	AForm(const str& name, const int gradeSign, const int gradeExec);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm&			operator=(const AForm& other);

	str				getName() const;
	int				getSignGrade() const;
	int				getExecGrade() const;
	bool			getSignedState() const;
	
	virtual void	execute(const Bureaucrat& executor) const = 0;
	void			beSigned(const Bureaucrat& bureaucrat);

	class AlreadySignedException : public std::runtime_error{
		public:
			AlreadySignedException();
	};

	class NotSignedException : public std::runtime_error{
		public:
			NotSignedException();
	};

private:
	const str	_name;
	const int	_requieredSignGrade;
	const int	_requieredExecGrade;
	bool		_isSigned;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#pragma once

#include <iostream>
#include <string>
#include <exception>	

#define MIN_GRADE 150
#define MAX_GRADE 1

typedef std::string str;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const str& name, const int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);

	str		getName() const;
	int	getGrade() const;

	void	incrementGrade(int nbr);
	void	incrementGrade();

	void	decrementGrade(int nbr);
	void	decrementGrade();

	class GradeTooLowException : public std::runtime_error{
		public:
			GradeTooLowException();
	};

	class GradeTooHighException : public std::runtime_error{
		public:
			GradeTooHighException();
	};

private:
	str	_name;
	int	_grade;
};

void	checkGrade(int grade);
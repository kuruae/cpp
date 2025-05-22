#include "Bureaucrat.hpp"
#include "Form.hpp"

void	checkGrade(int grade)
{
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(50) {}

Bureaucrat::Bureaucrat(const str& name, const int grade) :
_name(name.empty() ? "Unknown" : name)
{
	checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
_name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

str Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::incrementGrade(int nbr)
{
	checkGrade(this->_grade - nbr);
	this->_grade -= nbr;
}

void Bureaucrat::incrementGrade()
{
	checkGrade(this->_grade - 1);
	this->_grade--;
}

void Bureaucrat::decrementGrade(int nbr)
{
	checkGrade(this->_grade + nbr);
	this->_grade += nbr;
}

void Bureaucrat::decrementGrade()
{
	checkGrade(this->_grade + 1);
	this->_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
std::runtime_error("Grade too low") {}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
std::runtime_error("Grade too high") {}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (os);
}

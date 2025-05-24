#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::createShrubberyCreationForm(const str& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const str& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const str& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const str& formName, const str& target) const
{
	const str formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm* (Intern::*formCreators[])(const str&) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (size_t i = 0; i < (sizeof(formNames) / sizeof(formNames[0])); ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cerr << "Intern: Form '" << formName << "' not found." << std::endl;
	throw FormNotFoundException();
}

Intern::FormNotFoundException::FormNotFoundException() :
	std::runtime_error("Intern: Form not found") {}
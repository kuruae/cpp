#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const str& target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target.empty() ? "default" : target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade()),
	_target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignedState() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	this->createShrubbery();
}

void ShrubberyCreationForm::createShrubbery() const
{
	str filename = this->_target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs)
        throw std::runtime_error("Could not create file: " + this->_target + "_shrubbery");

    ofs << "          .     .  .      +     .      .          .\n"
        << "     .       .      .     #       .           .\n"
        << "        .      .         ###            .      .      .\n"
        << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
        << "          .      . \"####\"###\"####\"  .\n"
        << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
        << "  .             \"#########\"#########\"        .        .\n"
        << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
        << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
        << "                .\"##\"#####\"#####\"##\"           .      .\n"
        << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
        << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
        << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
        << "            .     \"      000      \"    .     .\n"
        << "       .         .   .   000     .        .       .\n"
        << ".. .. ..................O000O........................ ...... ...\n" << std::endl;
    
    ofs << "               ,@@@@@@@,\n"
        << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
        << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
        << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
        << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
        << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
        << "       |o|        | |         | |\n"
        << "       |.|        | |         | |\n"
        << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n" << std::endl;

    ofs << "         v\n"
        << "        >X<\n"
        << "         A\n"
        << "        d$b\n"
        << "      .d\\$$b.\n"
        << "    .d$i$$\\$$b.\n"
        << "       d$$@b\n"
        << "      d\\$$$ib\n"
        << "    .d$$$\\$$$b\n"
        << "  .d$$@$$$$\\$$ib.\n"
        << "      d$$i$$b\n"
        << "     d\\$$$$@$b\n"
        << "  .d$@$$\\$$$$$@b.\n"
        << ".d$$$$i$$$\\$$$$$$b.\n"
        << "        ###\n"
        << "        ###\n"
        << "        ###\n" << std::endl;
    
	ofs.close();
  
	if (ofs.fail())
        throw std::runtime_error("Failed to write to file: " + this->_target + "_shrubbery");
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{   
    try {
        std::cout << "===== CREATING FORMS & BUREAUCRATS =====" << std::endl;
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("R2D2");
        PresidentialPardonForm pardon("Han Solo");
        
        Bureaucrat lowLevel("Gardener", 145);		// Can only sign ShrubberyCreationForm
        Bureaucrat midLevel("Robot Manager", 40);	// Can sign and execute Shrubbery and Robotomy
        Bureaucrat highLevel("President", 1);		// Can do everything
        
        std::cout << "\n===== SUCCESSFUL EXECUTION TESTS =====" << std::endl;
        
        std::cout << "\n>> Testing ShrubberyCreationForm (should succeed):" << std::endl;
        lowLevel.signForm(shrub);
        midLevel.executeForm(shrub);
        
        std::cout << "\n>> Testing RobotomyRequestForm (should succeed):" << std::endl;
        midLevel.signForm(robot);
        midLevel.executeForm(robot);
        
    
        std::cout << "\n>> Testing PresidentialPardonForm (should succeed):" << std::endl;
        highLevel.signForm(pardon);
        highLevel.executeForm(pardon);
        
        std::cout << "\n===== GRADE TOO LOW TESTS =====" << std::endl;
        

        std::cout << "\n>> Testing signing with too low grade:" << std::endl;
        PresidentialPardonForm pardon2("Greedo");
        lowLevel.signForm(pardon2); 
        
        std::cout << "\n>> Testing execution with too low grade:" << std::endl;
        ShrubberyCreationForm shrub2("yard");
        highLevel.signForm(shrub2);
        lowLevel.executeForm(shrub2); 
        
        std::cout << "\n===== UNSIGNED FORM TEST =====" << std::endl;
        
        // Unsigned form
        std::cout << "\n>> Testing execution of unsigned form:" << std::endl;
        RobotomyRequestForm robot2("R2D2");
        highLevel.executeForm(robot2);
        
        std::cout << "\n===== INVALID PATH TEST =====" << std::endl;
        
        // Non-writable path for Shrubbery
        std::cout << "\n>> Testing ShrubberyCreationForm with invalid path:" << std::endl;
        ShrubberyCreationForm shrub3("/root/uwu");
        highLevel.signForm(shrub3);
        highLevel.executeForm(shrub3);
        
    } catch (std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }
    
    return 0;
}
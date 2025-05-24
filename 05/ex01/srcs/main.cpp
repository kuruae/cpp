#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "==== FORM CREATION TESTS ====" << std::endl;
	
	try {
		Form form1("Paper", 50, 25);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n==== INVALID FORM GRADE TESTS ====" << std::endl;
	
	try {
		Form form2("Invalid High Sign", 0, 25);  // Should throw GradeTooHighException
	}
	catch (std::exception &e) {
		std::cout << "Sign grade too high test error: " << e.what() << std::endl;
	}

	try {
		Form form3("Invalid Low Exec", 50, 151);  // Should throw GradeTooLowException
	}
	catch (std::exception &e) {
		std::cout << "Exec grade too low test error: " << e.what() << std::endl;
	}

	std::cout << "\n==== BUREAUCRAT SETUP ====" << std::endl;

	Bureaucrat alice("Alice", 30);
	Bureaucrat janna("Janna", 75);
	Form importantForm("Important Document", 50, 25);
	Form secretForm("Secret Document", 10, 5);

	std::cout << alice << std::endl;
	std::cout << janna << std::endl;
	std::cout << importantForm << std::endl;
	std::cout << secretForm << std::endl;

	std::cout << "\n==== SUCCESSFUL SIGNING TEST ====" << std::endl;
	
	// Alice (grade 30) should be able to sign importantForm (requires grade 50)
	alice.signForm(importantForm);
	std::cout << "After signing: \n" << importantForm << std::endl;

	std::cout << "\n==== FAILED SIGNING TEST ====" << std::endl;
	
	// Janna (grade 75) should NOT be able to sign importantForm (requires grade 50)
	janna.signForm(importantForm);

	std::cout << "\n==== ALREADY SIGNED FORM TEST ====" << std::endl;
	
	// Try to sign an already signed form
	alice.signForm(importantForm);

	std::cout << "\n==== HIGH-LEVEL FORM TEST ====" << std::endl;
	
	// Both should fail to sign the secret form (requires grade 10)
	alice.signForm(secretForm);
	janna.signForm(secretForm);

	std::cout << "\n==== CREATING HIGH-LEVEL BUREAUCRAT ====" << std::endl;
	
	try {
		Bureaucrat president("President", 1);
		std::cout << president << std::endl;
		
		// President should be able to sign any form
		president.signForm(secretForm);
		std::cout << "After president signing: \n" << secretForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error creating president: " << e.what() << std::endl;
	}

	std::cout << "\n==== FORM beSigned() DIRECT TEST ====" << std::endl;
	
	try {
		Form directTest("Direct Test", 100, 50);
		Bureaucrat testBureaucrat("Tester", 80);
		
		std::cout << "Before beSigned: \n" << directTest << std::endl;
		directTest.beSigned(testBureaucrat);  // Should work (80 < 100)
		std::cout << "After beSigned: \n" << directTest << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Direct beSigned error: " << e.what() << std::endl;
	}

	std::cout << "\n==== FORM beSigned() FAILURE TEST ====" << std::endl;
	
	try {
		Form strictForm("Strict Form", 20, 10);
		Bureaucrat lowGrade("Low Grade", 50);
		
		std::cout << "Before failed beSigned: \n" << strictForm << std::endl;
		strictForm.beSigned(lowGrade);  // Should fail (50 > 20)
	}
	catch (std::exception &e) {
		std::cout << "Expected failure: " << e.what() << std::endl;
	}

	return 0;
}
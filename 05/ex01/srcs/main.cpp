#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat obj1("obj1", 150);

	std::cout << obj1.getName() << "'s grade is " << obj1.getGrade() << std::endl; 


	std::cout << "==== TEST 1 ====" << std::endl;
	
	try{
		Bureaucrat obj2("obj2", 170);
	}
	catch (std::exception &e){
		std::cout << e.what() << "\n" << std::endl;
	}

	std::cout << "==== TEST 2 ====" << std::endl;
	
	try{
		Bureaucrat obj3("obj3", -12);
	}
	catch (std::exception &e){
		std::cout << e.what() << "\n" << std::endl;
	}

	std::cout << "==== TEST 3 ====" << std::endl;
	
	try{
		Bureaucrat obj4("obj4", 12);
	}
	catch (std::exception &e){
		std::cout << e.what() << "\n" << std::endl; // <-- not reached
	}

	std::cout << "==== TEST 4 ====" << std::endl;
	
	try{
		Bureaucrat obj5("obj5", 5);

		for (int i = 0; i < 7; i++)
		{
			std::cout << "current grade: " << obj5.getGrade() << std::endl;
			obj5.incrementGrade();
		}
	}
	catch (std::exception &e){
		std::cout << e.what() << "\n" << std::endl;
	}

	std::cout << "==== TEST 5 ====" << std::endl;
	
	try{
		Bureaucrat obj6("obj6", 100);

		std::cout	<< "current grade: " << obj6.getGrade() 
					<< "\nnow trying to decrement from 70 grades..." << std::endl;

		obj6.decrementGrade(70);

		std::cout	<< "success!" << std::endl; // <-- not reached 
	}
	catch (std::exception &e){
		std::cout << e.what() << "\n" << std::endl;
	}

	

	return 0;
}
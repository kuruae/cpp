#include <iostream>
#include <vector>

#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define CYAN		"\033[36m"

#include "MutantStack.hpp"

int main()
{
	std::cout << YELLOW BOLD << "==== BASE SUBJECT'S TEST ====" << RESET << std::endl;
	try{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
		return 1;
	}

	std::cout << YELLOW BOLD << "\n\n==== OUR TESTS ====" << RESET << std::endl;
	try {
		std::cout <<GREEN<< "- First running std::stack tests -" <<RESET<< std::endl;


		std::cout << "Making a vector-adapted stack of floats..." << std::endl;
		std::stack< float, std::vector<float> > floatingStack;
		
		if (floatingStack.empty())
			std::cout << "floatingStack is empty\n" << std::endl;

		std::cout << "pushing 12, -0.75, 87, 54, then popping...\n" << std::endl;
		floatingStack.push(12);
		floatingStack.push(-0.75);
		floatingStack.push(87);
		floatingStack.push(54);
		floatingStack.pop();

		std::cout << "printing top element: " << floatingStack.top() << std::endl;

		//================

		std::cout << GREEN << "\n\n" << 
					"- Now executing the same test suit with our MutantStack. -" <<RESET<< std::endl;

		std::cout << "Making a vector-adapted stack of floats..." << std::endl;
		MutantStack<float, std::vector<float> > MStackFloat;
		
		if (MStackFloat.empty())
			std::cout << "MStackFloat is empty\n" << std::endl;

		std::cout << "pushing 12, -0.75, 87, 54, then popping...\n" << std::endl;
		MStackFloat.push(12);
		MStackFloat.push(-0.75);
		MStackFloat.push(87);
		MStackFloat.push(54);
		MStackFloat.pop();

		std::cout << "printing top element: " << MStackFloat.top() << std::endl;


		//==============


		std::cout << GREEN<< "\n- Testing iterators -" <<RESET<< std::endl;

		MutantStack<float, std::vector<float> > newMStack = MStackFloat;

		MutantStack<float, std::vector<float> >::iterator it = MStackFloat.begin();

		std::cout	<< "making a copy of MStackFloat..\n\n"
					<< "printing the entire stack with iterators,"
					<< " then changing there value through dereferencing:" << std::endl;
		
		while(it != MStackFloat.end())
		{
			std::cout << "old: " << *it << "\n";
			*it *= 2;
			std::cout << "new: " << *it << "\n\n";
			it++;
		}

		std::cout << "MStackFloat top() value: " << MStackFloat.top() << std::endl;
		std::cout << "Backup copy top() value: " << newMStack.top() << std::endl;
		
		std::cout << "\nnow after running stack member method swap()...\n" << std::endl;
		MStackFloat.swap(newMStack);

		std::cout << "MStackFloat top() value: " << MStackFloat.top() << std::endl;
		std::cout << "Backup copy top() value: " << newMStack.top() << std::endl;
		


	} catch (const std::exception& e) {
		std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
		return 1;
	}
	
	std::cout << YELLOW << "\n==== END OF TEST~ ====" << RESET << std::endl;

	return 0;
}
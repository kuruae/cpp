#include "Setup.hpp"

void	handle_command(const std::string& string, PhoneBook& phoneBook)
{
	if (string == "ADD")
		phoneBook.addContact();
	else if (string == "SEARCH")
		phoneBook.searchContact();
	else if (string == "EXIT")
		return ;
	else
		std::cout << RED "error: " END << string << " is an invalid command" << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string userInput;

	std::cout << "Welcome to your phonebook\n-----\n";

	while (userInput != "EXIT")
	{
		std::cout << "commands: ADD - SEARCH - EXIT\nInput a valid command of your choice: ";
		std::getline(std::cin, userInput);
		if (userInput.empty())
			continue;
		handle_command(userInput, phoneBook);
	}

	return 0;
}
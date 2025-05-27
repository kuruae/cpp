#include "Serializer.hpp"

#define RESET		"\033[0m"
#define CYAN		"\033[36m"
#define YELLOW		"\033[33m"
#define RED			"\033[31m"
#define BOLD		"\033[1m"

int	main(void)
{

	std::cout << BOLD "==== Serializer Test ====" RESET << "\n"
			  << "testing with a Data pointer,"
			  << "containing the string \"Test Data\" "
			  << "and the integer value 42\n" << std::endl;


	Data *data = new Data();
	uintptr_t ptr;

	data->name = "Test Data";
	data->value = 42;
	try {
		ptr = Serializer::serialize(data);
		Data *tmp = Serializer::deserialize(ptr);

		std::cout	<< CYAN "Data ptr: " YELLOW << data << RESET << " -> name: " << data->name
					<< ", integer value: " << data->value << std::endl;
		
		std::cout << CYAN "Serialized ptr(type = uintptr_t): " YELLOW << ptr << RESET << std::endl;
		
		if (tmp)
			std::cout	<< CYAN "Deserialized ptr(type = Data): " YELLOW << tmp << RESET << " -> name: "
						<< tmp->name << ", integer value: " << tmp->value << std::endl;
		else
			std::cout << RED "Deserialized ptr is NULL" RESET << std::endl;
			
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout << BOLD "\n==== Null Pointer Test ====" RESET << std::endl;

	Data *nullData = 0;
	try {
		ptr = Serializer::serialize(nullData);
	} catch (std::exception &e) {
		std::cout << RED <<e.what() << RESET << std::endl;
	}
	
	delete data;
	return (0);
}
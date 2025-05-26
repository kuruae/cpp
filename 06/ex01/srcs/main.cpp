#include "Serializer.hpp"

int	main(void)
{

	std::cout << "==== Serializer Test ====" << "\n"
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

		std::cout	<< "Data ptr: " << data << " -> name: " << data->name
					<< ", integer value: " << data->value << std::endl;
		
		std::cout << "Serialized ptr(type = uintptr_t): " << ptr << std::endl;
		
		if (tmp)
			std::cout	<< "Deserialized ptr(type = Data): " << tmp << " -> name: "
						<< tmp->name << ", integer value: " << tmp->value << std::endl;
		else
			std::cout << "Deserialized ptr is NULL" << std::endl;
			
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n==== Null Pointer Test ====" << std::endl;

	Data *nullData = 0;
	try {
		ptr = Serializer::serialize(nullData);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	delete data;
	return (0);
}
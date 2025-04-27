#include <iostream>
#include <string>
#include <fstream>



int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "wrong number of arguments (argc = " << argc << ", should be 4)"
		<< std::endl;
		return(1);
	}
	(void)argc;
	std::ofstream file;
	file.open (argv[1]);
	file << "aaaaaaa\n";
	file.close();
	return 0;
}
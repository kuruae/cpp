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
	
	std::string fileLine;
	std::string filePath = argv[1];
	std::string subFind = argv[2];
	std::string subReplace = argv[3];

	std::ifstream file(filePath.c_str());
	if (!file.is_open())
	{
		std::cout << "could not open file " << filePath << std::endl;
		return(1);
	}
	std::string appendFilename = filePath + ".replace";
	std::ofstream destFile;
	destFile.open(appendFilename.c_str());
	if (!destFile.is_open())
	{
		std::cout << "could not open file " << filePath << std::endl;
		return(1);
	}
	while (getline(file, fileLine))
	{
		size_t start = fileLine.find(subFind);
		if (start != std::string::npos)
		{
			fileLine.erase(start, subFind.length());
			fileLine.insert(start, subReplace);
		}
		destFile << fileLine << "\n";
	}
	file.close();
	destFile.close();
	return 0;
}
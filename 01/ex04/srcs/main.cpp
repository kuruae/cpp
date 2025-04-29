#include <iostream>
#include <string>
#include <fstream>

void replaceLine(const std::string& findStr, const std::string& replaceStr, std::string& currLine)
{
    if (findStr.empty())
        return;
    
    size_t pos = 0;
    while ((pos = currLine.find(findStr, pos)) != std::string::npos)
    {
        currLine.erase(pos, findStr.length());
        currLine.insert(pos, replaceStr);
        pos += replaceStr.length();
    }
}

void processFile(const std::string& inputPath, const std::string& findStr, const std::string& replaceStr)
{
	std::ifstream inputFile(inputPath.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Could not open input file: " + inputPath);
	
	std::string outputPath = inputPath + ".replace";
	std::ofstream outputFile;

	outputFile.open(outputPath.c_str());
	if (!outputFile.is_open()) {
		inputFile.close();
		throw std::runtime_error("Could not create output file: " + inputPath);
	}

	std::string currLine;
	while (getline(inputFile, currLine)) {
		replaceLine(findStr, replaceStr, currLine);
		outputFile << currLine << "\n";
	}
	outputFile.close();
	inputFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr	<< "Error: Incorrect number of arguments.\n" << "Usage: " << argv[0]
					<< " <filename> <string_to_find> <string_to_replace>" << std::endl;
		return(1);
	}
	
	std::string fileLine;
	std::string filePath = argv[1];
	std::string findStr = argv[2];
	std::string replaceStr = argv[3];
	
	try {
		processFile(filePath, findStr, replaceStr);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown error" << std::endl;
	}

	return 0;
}
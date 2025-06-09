#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define CYAN		"\033[36m"

typedef std::string string_t;

class PmergeMe
{
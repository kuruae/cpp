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

class RPN
{
public:
	RPN();
	RPN(const RPN& other);
	~RPN();

	RPN& operator=(const RPN& other);

	void	run(const string_t& input);
	
private:
    void	validateToken(const string_t& token) const;
    void	processToken(const string_t& token);
    void	processNumber(const string_t& token);
    void	processOperator(char op);
    
    int		calculate(int a, int b, char op) const;
    
    void	validateFinalResult() const;
    void	printResult(string_t const& color) const;


	std::stack<int>	_stack;
	int				_result;

};
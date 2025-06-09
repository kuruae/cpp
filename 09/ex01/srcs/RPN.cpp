#include "RPN.hpp"

RPN::RPN() : _result(0) {}

RPN::RPN(const RPN& other) :
_result(0) {(void)other;}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

static bool is_operator(const char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::run(const string_t& input)
{
    if (input.empty())
        throw std::invalid_argument("Input cannot be empty");

    std::stringstream ss(input);
    string_t token;
    
    while (ss >> token)
    {
        validateToken(token);
        processToken(token);
    }
    
    validateFinalResult();
    printResult(GREEN);
}

void RPN::validateToken(const string_t& token) const
{
    if (token.size() != 1 || (!isdigit(token[0]) && !is_operator(token[0])))
        throw std::invalid_argument("Invalid token: " + token);
}

void RPN::processToken(const string_t& token)
{
    if (isdigit(token[0]))
        processNumber(token);
    else
        processOperator(token[0]);
}

void RPN::processNumber(const string_t& token)
{
    _stack.push(std::atoi(token.c_str()));
}

void RPN::processOperator(char op)
{
    if (_stack.size() < 2)
        throw std::invalid_argument("Not enough operands in stack for operation");
    
    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();
    
    _result = calculate(a, b, op);
    _stack.push(_result);
}

int RPN::calculate(int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::domain_error("Division by zero");
			return (a / b);
		default:
			throw std::invalid_argument("Invalid operator");
	}
}

void RPN::validateFinalResult() const
{
    if (_stack.size() != 1)
        throw std::invalid_argument("Too many values in the stack");
}

void RPN::printResult(string_t const& color) const
{
    std::cout << color << "Final result: " << _stack.top() << RESET << std::endl;
}

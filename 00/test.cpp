#include <iostream>

class ClassName
{
public:
	int var;
	int& foo;
	ClassName(int a, int& b);
	~ClassName(void); 
	int fake_function(void);

private:
	int private_var = 8;
};

int ClassName::fake_function()
{
	this->private_var = 42 * 42;
	std::cout << this->private_var << std::endl;
	return 0;
}

ClassName::ClassName(int a, int &b) : var(a), foo(b)
{
	std::cout << a + b << std::endl;
	return;
}

ClassName::~ClassName()
{
	std::cout << "destructor has been called" << std::endl;
	return;
}

int main(void)
{
	int x = 300;
	ClassName ObjectName(11, x);
	std::cout << ObjectName.var << std::endl;
	std::cout << ObjectName.foo << std::endl;

	return 0;
}
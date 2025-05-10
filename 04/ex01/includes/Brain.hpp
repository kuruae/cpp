#pragma once
#include <string>
#include <iostream>

typedef std::string str;

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain& operator=(const Brain& other);
	
	void	readBrain() const;

private:
	str _ideas[100];

};
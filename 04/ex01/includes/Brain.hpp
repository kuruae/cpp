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
	void	setIdea(int const index, const str &idea);
	str		getIdea(int const index) const;

private:
	str _ideas[100];

};
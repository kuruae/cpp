#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* arrayZombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		arrayZombies[i].setName(name);
	}
	return arrayZombies;
}
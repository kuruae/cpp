#include "Zombie.hpp"

int main()
{
	int n = 69;
	Zombie *horde = zombieHorde(n, "Mario");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}
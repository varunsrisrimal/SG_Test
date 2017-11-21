#include "stdafx.h"

#define arraySize 6

int FindAliveCount(const int(&birth)[arraySize], const int(&death)[arraySize], int year)
{
	int aliveCount = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (birth[i] < year && death[i] > year)
		{
			aliveCount++;
		}
	}
	return aliveCount;
}


int main()
{
	//feel free to update this list and dont forget to update the #define
	//this is assuming every person has a birth and death year given

	// Birth - Death
	// 1900	 - 1920
	// 1914	 - 1956
	// 1919	 - 1942
	// 1942	 - 1990
	// 1912	 - 1996
	// 1901	 - 1999

	int birthYear[arraySize] = { 1900, 1914, 1919, 1942, 1912, 1901 };
	int deathYear[arraySize] = { 1920, 1956, 1942, 1990, 1996, 1999 };

	//will be update when a new max count is found
	int maxAliveCount = 0;

	std::map<int, std::vector<int> > population;
	std::map<int, std::vector<int> >::iterator it;


	for (int i = 0; i < arraySize; i++)
	{
		std::vector<int> tempVector;
		
		int currentYear = deathYear[i] - 1;

		int numOfPeopleAlive = FindAliveCount(birthYear, deathYear, currentYear);
		
		it = population.find(numOfPeopleAlive);
		
		if(it != population.end())
		{
			tempVector = population.at(numOfPeopleAlive);
		}

		tempVector.push_back(currentYear);

		population[numOfPeopleAlive] = tempVector;

		if (maxAliveCount < numOfPeopleAlive)
		{
			maxAliveCount = numOfPeopleAlive;
		}
	}

	if (population[maxAliveCount].size() > 1)
	{
		std::cout << "The years with most people alive are ";

		for (unsigned int i = 0; i < population[maxAliveCount].size(); i++)
		{
			std::cout << population[maxAliveCount][i] << " | ";
		}

		std::cout << " with a total of " << maxAliveCount << " people alive.\n";
	}
	else
	{
		std::cout << "The year with most people alive is" << population[maxAliveCount].back();
		std::cout << " with a total of " << maxAliveCount << " people alive.\n";
	}

	system("pause");
    return 0;
}



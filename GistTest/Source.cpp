#include <iostream>
#include <string>
float One(float a, float b, float c)
{
	return 5 * (a + b + c);
}
void Two(int * point, int s)
{
	for (int i = 2; i < (s * 2) + 2; i += 2)
	{
		*point = i;
		point++;
	}
}
void Three(char point[], int size)
{
	for (int i = 1; i <= size / 2; i++)
	{
		char tmp = point[i - 1];
		point[i - 1] = point[size - i];
		point[size - i] = tmp;
	}
}
class Cat
{
private:
	char m_name;
public:
	Cat() {};
	void NameMe(char n)
	{
		m_name = n;
	}
};
int Five(int * array, int size)
{
	int b = 0;
	int LargestNum = 0;
	for (int i = 0; i < size; i++)
	{
		int Counter = 0;
		for (int x = 0; x < size; x++)
		{
			if (array[i] == array[x])
			{
				Counter++;
				if (Counter > b)
				{
					LargestNum = array[x];
					b = Counter;
				}
			}
		}
	}
	return LargestNum;
}
void Six(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void Seven(std::string strings[], int length)
{
	for (int i = 0; i <= length*length; i++) // Loops throught the entire array 
	{
		if (i % length != 0) //Checks if we are going out of range
		{
			for (int x = 0;; x++) //Loops through each character of each string in the array 
			{
				if (strings[(i % length) - 1] == strings[i % length]) //Checks if the two strings are equal to each other
				{
					break;
				}
				else if (strings[(i % length) - 1][x] == NULL) //If at the end of the first word break
				{
					break;
				}
				else if (strings[(i % length)][x] == NULL) //If at the end of the second word swap them
				{
					std::string tmp = strings[(i % length) - 1];
					strings[(i % length) - 1] = strings[i % length];
					strings[i % length] = tmp;
					break;
				}
				else if (strings[(i % length) - 1][x] > strings[i % length][x]) //If character in the first word are greater than second word swap them
				{
					std::string tmp = strings[(i % length) - 1];
					strings[(i % length) - 1] = strings[i % length];
					strings[i % length] = tmp;
					break;
				}
				else if (strings[(i % length) - 1][x] < strings[i % length][x]) //If they are less than break
				{
					break;
				}
			}
		}
	}
}
int main()
{
	//1 
	One(5.1, 6.33, 7);
	//2
	int arrays[5];
	int * ptr = arrays;
	Two(ptr, 5);
	//3
	char point[] = { "DON" };
	int size = 3;
	Three(point, size);
	std::cout << point << std::endl;
	//4
	Cat Work[26];
	int i = 0;
	while (i < 26)
	{
		if (i % 2 == 0)
		{
			Work[i].NameMe(i + 65); //Upper
		}
		else
		{
			Work[i].NameMe(i + 97); //Lower
		}
		i++;
	}
	//5
	int array[] = { 1,2,13,1,5,66 };
	int sum = Five(array, 6);
	std::cout << sum << std::endl;
	//6
	int firstN = 5;
	int secondN = 10;
	Six(firstN, secondN);
	std::cout << firstN << std::endl;
	//7
	//Tried other ways none of them worked this only way that worked 
	std::string strings[5] = { "black", "white", "orange", "yellow", "blue" };
	Seven(strings, 5);
	system("pause");
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	while (getline(cin, str))
	{
		int lower = 0;
		int upper = 0;
		int number = 0;
		int space = 0;

		for (char c : str)
		{
			if (islower(c))
			{
				lower++;
			}
			else if (isupper(c))
			{
				upper++;
			}
			else if (isspace(c))
			{
				space++;
			}
			else if (isdigit(c))
			{
				number++;
			}
		}
		printf("%d %d %d %d\n", lower, upper, number, space);
	}
}
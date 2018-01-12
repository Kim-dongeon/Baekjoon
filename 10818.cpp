#include <iostream>

int main()
{
	int n,max=-1000000,min=1000000;
	int *p = new int[1000000];
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> p[i];
		if (min > p[i])
		{
			min = p[i];
		}
		if (max < p[i])
		{
			max = p[i];
		}
	}



	std::cout << min << ' ' << max;
	delete[]p;
}
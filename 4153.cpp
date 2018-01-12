#include <iostream>

int main()
{
	int a[3],max=0,max_i=0,sum=0;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			std::cin >> a[i];
			if (max < a[i])
			{
				max = a[i];
				max_i = i;
			}
		}
		if (a[0] == 0 && a[1]== 0 && a[2] == 0)
		{
			return 0;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i != max_i)
			{
				sum += a[i] * a[i];
			}
			else
			{
				sum -= a[i] * a[i];
			}
		}
		if (sum == 0)
		{
			std::cout << "right" << std::endl;
		}
		else
		{
			std::cout << "wrong" << std::endl;
		}
		
		max = 0;
		sum = 0;



		

	}
	
}
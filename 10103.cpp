#include <iostream>

int main()
{
	int n,A,B,s_A=100,s_B=100;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> A >> B;
		if (A > B)
		{
			s_B -= A;
		}
		else if(A<B)
		{
			s_A -= B;
		}
	}

	std::cout << s_A << std::endl << s_B;

	
}
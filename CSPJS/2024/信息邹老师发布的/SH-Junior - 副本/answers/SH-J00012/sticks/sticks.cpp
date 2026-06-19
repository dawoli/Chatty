#include <iostream>
#include <fstream>
#include <stack>

std::ifstream fin("sticks.in");
std::ofstream fout("sticks.out");
std::stack<int> nums;

int main()
{
	int t;
	std::cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n;
		std::cin >> n;
		if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0) fout << -1 << std::endl;
		else if(n % 7 == 0)
		{
			for(int i = 1; i <= n / 7; i++) std::cout << 8;
		}
		else
		{
			while(n > 0)
			{
				if(n >= 9 || n ==7)
				{
					nums.push(8);
					n -= 7;
				}
				else if(n >= 8)
				{
					nums.push(0);
					n -= 6;
				}
				else if(n == 6)
				{
					nums.push(6);
					n -= 6;
				}
				else if(n >= 5)
				{
					nums.push(2);
					n -= 5;
				}
				else if(n >= 4)
				{
					nums.push(4);
					n -= 4;
				}
				else if(n >= 3)
				{
					nums.push(7);
					n -= 3;
				}
				else if(n >= 2)
				{
					nums.push(2);
					n -= 2;
				}
			}
			while(!nums.empty()){
				fout << nums.top();
				nums.pop();
			}
		}

	}

}

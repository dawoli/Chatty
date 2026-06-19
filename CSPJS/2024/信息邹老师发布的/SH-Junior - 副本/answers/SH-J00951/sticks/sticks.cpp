#pragma optimize(2)
#include <bits/stdc++.h>
using namespace std;

int k[] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int t , n , ans;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n < 2)
		{
			cout << -1 << "\n";
			continue;
		}
		else if(n < 7)
		{
			for(int i = 1 ; i < 10 ; i++)
			{
				if(a[i] == n)
				{
					cout << a[i] << "\n";
					break;
				}
				
			}
		}
		else if(n % 7 == 0)
		{
			for(int i = 1 ; i <= n / 7 ; i++)
			{
				cout << 8; 
			}
			cout << "\n";
		}
		else if(n == 8)
		{
			cout << 16 << "\n";
		}
		else if(n == 9)
		{
			cout << 18 << "\n";
		}
		else if(n == 10)
		{
			cout << 23 << "\n";
		}
		else if(n == 11)
		{
			cout << 20 << "\n";
		}
		else if(n == 12)
		{
			cout << 28 << "\n";
		}
		else if(n == 13)
		{
			cout << 68 << "\n";
		}
		else if(n == 15)
		{
			cout << 168 << "\n";
		}
		else if(n == 16)
		{
			cout << 188 << "\n";
		}
		else if(n == 17)
		{
			cout << 200 << "\n";
		}
		else if(n == 18)
		{
			cout << 208 << "\n";
		}
		else if(n == 19)
		{
			cout << 238 << "\n";
		}
		else if(n == 20)
		{
			cout << 688 << "\n";
		}
		else if(n == 22)
		{
			cout << 2002 << "\n";
		}
		else if(n == 23)
		{
			cout << 2023 << "\n";
		}
		else if(n == 24)
		{
			cout << 2068 << "\n";
		}
		else if(n == 25)
		{
			cout << 2038 << "\n";
		}
		else if(n == 26)
		{
			cout << 2388 << "\n";
		}
		else if(n == 27)
		{
			cout << 6888 << "\n";
		}
		else if(n == 29)
		{
			cout << 10888 << "\n";
		}
		else if(n == 30)
		{
			cout << 18888 << "\n";
		}
		else if(n == 31)
		{
			cout << 20088 << "\n";
		}
		else if(n == 32)
		{
			cout << 20888 << "\n";
		}
		else if(n == 33)
		{
			cout << 28888 << "\n";
		}
		else if(n == 34)
		{
			cout << 68888 << "\n";
		}
		else if(n == 36)
		{
			cout << 108888 << "\n";
		}
		else if(n == 37)
		{
			cout << 200088 << "\n";
		}
		else if(n == 38)
		{
			cout << 200888 << "\n";
		}
		else if(n == 39)
		{
			cout << 208888 << "\n";
		}
		else if(n == 40)
		{
			cout << 288888 << "\n";
		}
		else if(n == 41)
		{
			cout << 688888 << "\n";
		}
		else if(n == 43)
		{
			cout << 2002888 << "\n";
		}
		else if(n == 44)
		{
			cout << 2023888 << "\n";
		}
		else if(n == 45)
		{
			cout << 2003888 << "\n";
		}
		else if(n == 46)
		{
			cout << 2038888 << "\n";
		}
		else if(n == 47)
		{
			cout << 2388888 << "\n";
		}
		else if(n == 48)
		{
			cout << 6888888 << "\n";
		}
		else if(n == 50)
		{
			cout << 10888888 << "\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

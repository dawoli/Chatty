#pragma optimize(2)
#include <bits/stdc++.h>
using namespace std;

int n , x , need = 52;
char color , num;
bool f[100][15]; 

int main()
{
    freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	   
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> color >> num;
		if(num == 'A')
		{
			x = 1; 
		}
		else if(num == 'T')
		{
			x = 10;
		}
		else if(num == 'J')
		{
			x = 11;
		}
		else if(num == 'Q')
		{
			x = 12;
		}
		else if(num == 'K')
		{
			x = 13;
		}
		else
		{
			x = num - '0';
		}
		if(f[color][x] == 0)
		{
			need--;
			f[color][x] = 1;
		}
	}
	
	cout << need;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

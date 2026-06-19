#include <bits/stdc++.h>
using namespace std;
int t,s;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)	
	{
		cin >> s;
		if(s == 1) cout << -1;
		if(s == 2) cout << 1;
		if(s == 3) cout << 7;
		if(s == 6) cout << 6;
		if(s == 8) cout << 10;
		else if(s % 7 == 0)
		{
			string x;
			for(int j = 1; j <= s/7; j++)
				x += '8';
			cout << x;
		}
		else if(s % 7 == 1 && s > 8)
		{
			string y = "8";
			for(int j = 1; j <= s/7-1; j++)
				y+="01";
			cout << y; 
		}
	}
	return 0;
}

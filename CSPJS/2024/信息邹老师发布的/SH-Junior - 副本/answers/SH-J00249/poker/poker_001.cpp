#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, sum = 0, poker[14][5];
	memset(poker, 0, sizeof(poker));
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		string s;
		int hs = 0, sz = 0;
		cin >> s;
		switch(s[0])
		{
			case 'D':
				hs = 1;
				break;
			case 'C':
			    hs = 2;
			    break;
			case 'H':
				hs = 3;
				break;
			case 'S':
				hs = 4;
				break;
			default:
				break;
		}
		if(s[1] >= '2' && s[1] <= '9')
		    sz = (int)(s[1] - '0');
		else if(s[1] == 'A')
		    sz = 1;
		else 
		{
			switch(s[1])
			{
				case 'T':
					sz = 10;
					break;
				case 'J':
					sz = 11;
					break;
				case 'Q':
					sz = 12;
					break;
				case 'K':
					sz = 13;
					break;
				default:
					break;
			}
		}
		poker[sz][hs]++;
	}
	for(int i = 1;i <= 13;i++)
	    for(int j = 1;j <= 4;j++)
	        if(poker[i][j] == 0)
	            sum++;
	cout << sum;
	
	return 0;
}

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int a[10][20];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		s = "?" + s; 
		int t = 0,p = 0;
		if(s[2] == 'A')
		{
			t = 1;
		}
		else if(s[2] <= '9' && s[2] >= '0')
		{
			t = s[2] - '0';
		}
		else if(s[2] == 'T') t = 10;
		else if(s[2] == 'J') t = 11;
		else if(s[2] == 'Q') t = 12;
		else t = 13;
		if(s[1] == 'D') p = 1;
		else if(s[1] == 'C') p = 2;
		else if(s[1] == 'H') p = 3;
		else p = 4;
		a[p][t]++;
	}
	for(int i = 1;i <= 4;i++)
	{
		for(int j = 1;j <= 13;j++)
		{
			if(a[i][j] == 0)
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

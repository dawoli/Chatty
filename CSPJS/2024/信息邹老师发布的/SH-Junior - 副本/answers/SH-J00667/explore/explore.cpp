#include<bits/stdc++.h>
using namespace std;

int n,m,k,ud,lr,d,T,cnt;
char mp[1003][1003];

int main()
{
	cin>>T;
	while(T --)
	{
		cnt = 1;
		cin>>n>>m>>k>>ud>>lr>>d;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				cin>>mp[i][j];
		while(k > 0)
		{
			if(d == 0)
			{
				if(lr + 1 > m || mp[lr + 1][ud] == 'x')
				{
					d = (d + 1) % 4;
					k --;
					continue;
				}
				else
					k --,lr += 1,cnt ++;
			}
			if(k <= 0)break;
			if(d == 1)
			{
				if(ud + 1 > n || mp[lr][ud + 1] == 'x')
				{
					d = (d + 1) % 4;
					k --;
					continue;
				}
				else
					k --,ud += 1,cnt ++;
			}
			if(k <= 0)break;
			if(d == 2)
			{
				if(lr - 1 < 1 || mp[lr - 1][ud] == 'x')
				{
					d = (d + 1) % 4;
					k --;
					continue;
				}
				else
					k --,lr -= 1,cnt ++;
			}
			if(k <= 0)break;
			if(d == 3)
			{
				if(ud - 1 < 1 || mp[lr][ud - 1] == 'x')
				{
					d = (d + 1) % 4;
					k --;
					continue;
				}
				else
					k --,ud -= 1,cnt ++;
			}
		}
		cout<<cnt;
	}
	return 0;
} 

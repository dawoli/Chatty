/*
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in",  "r", stdin);
	freopen("seat.out",  "w", stdout);
	cin>>n>>m;
	int a[n+1][m+1],mc = 0,inn[n*m+1],b = -1;
	for(int i = 1;i < n*m;i++)
	{
		cin>>inn[i];
		if(inn[i] > b)
		{
			if(i == 0)
			{
				b=inn[i];
			}
			else
			{
				b = inn[i];
				mc+=1;
			}
		}
	}
	//cout<<mc<<endl;
	int x=1,y=1,ott,xh = 1;
	while(mc >= 0)
	{
		if(xh == mc){
			cout<<x<<' '<<y;
			break;
		}
		//cout<<x<<' '<<y<<' '<<xh<<endl;
		if(x%2 == 1)
		{
			if(y+1 <= m)
			{
				y++;
			}
			else x++;
		}
		else if(x%2 == 0)
		{
			if(y-1 >= 1)
			{
				y-=1;
			}
			else x++;
		}
		
		xh++;
	}
	return 0;
}

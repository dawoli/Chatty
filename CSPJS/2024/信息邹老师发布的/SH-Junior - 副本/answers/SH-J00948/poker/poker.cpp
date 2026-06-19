#include<bits/stdc++.h>
using namespace std;
long long a,c=0;
struct A
{
	char x;
	char y;
}b[10004];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i].x>>b[i].y ;
		int g=0;
		for(int j=1;j<i;j++)
		{
			if(b[j].x==b[i].x&&b[j].y==b[i].y)
			{
				g=1;
			}
		}
		if(g==0)
		{
			c++;
		}
	}
	cout<<52-c;
	return 0;
}

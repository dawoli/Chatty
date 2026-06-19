#include<bits/stdc++.h>
using namespace std;
int n,m,c[103],x;
bool cmp(int y,int z)
{
	return y>z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(char i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	x=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(c[i]==x)
		{
			if(((i-1)/n)%2==0)
			{
				cout<<(i-1)/n+1<<' '<<(i-1)%n+1;
				return 0;
			}
			else
			{
				cout<<(i-1)/n+1<<' '<<n-(i-1)%n;
				return 0;
			}
		}
	}
	return 0;
}

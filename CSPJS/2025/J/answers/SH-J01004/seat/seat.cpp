#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b[105]={0},d=1,m=0,n=0,x=0,y=0,s=0;
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>b[i];
		if(b[i]>b[0])
		{
			d+=1;
		}
	}
	s=d%n;
	if(s==0)
	{
		s=n;
	}
	if(s==n)
	{
		x=d/n;
	}
	else
	{
		x=d/n+1;
	}
	if(x%2==0)
	{
		y=n-s+1;
	}
	else
	{
		y=s;
	}
	cout<<x<<" "<<y;
	return 0;
}

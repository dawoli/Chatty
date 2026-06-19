#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a=0,b[5005]={0},maxx=0,c=0;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	maxx=max(max(b[0],b[1]),b[2]);
	if(b[0]+b[1]+b[2]>2*maxx)
	{
		c=1;
	}
	else
	{
		c=0;
	}
	cout<<c;
	return 0;
}

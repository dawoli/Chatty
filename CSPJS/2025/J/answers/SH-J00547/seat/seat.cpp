#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,a,p=1;
	cin>>x>>y>>a;
	for(int i=1;i<=x*y-1;i++)
	{
		int o;
		cin>>o;
		if(o>a) p++;
	}
	int anx,any;
	anx=(p-1)/x+1;
	if(p%(x*2)<=x && p%(x*2)>=1)
	{
		any=p%(x*2);
	}
	else if(p%(x*2)==0)
	{
		any=1;
	}
		else
	{
		any=(x*2+1)-p%(x*2);
	}
	cout<<anx<<" "<<any;
	
	return 0;
}

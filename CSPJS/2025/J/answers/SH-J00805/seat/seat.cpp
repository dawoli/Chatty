#include<bits/stdc++.h>
using namespace std;
int n,m,sc[105],xr,x=1,y=1,tmp;
bool cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>sc[i];
	}
	xr=sc[0];
	sort(sc,sc+n*m,cmp);
	if(sc[0]==xr)
	{
		cout<<1<<' '<<1;
		return 0;
	}
	for(int i=0;sc[i]>=xr;i++)
	{
		tmp++;
	}
	cout<<tmp%n+1<<' '<<tmp/n+1;
	return 0;
}


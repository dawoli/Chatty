#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a,t,pos=1,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++)
	{
		cin>>t;
		if(t>a)pos++;
	}
	c=ceil(1.0*pos/n);
	if(c&1)r=pos-(c-1)*m;
	else r=n+1-pos+(c-1)*m;
	cout<<c<<' '<<r;
	return 0;
}

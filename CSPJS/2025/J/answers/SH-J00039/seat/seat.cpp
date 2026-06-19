#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],k,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++)
	{
		if(k==a[i])
		{
			p=n*m-i+1;
			break;
		}
	}
	int x=p%n,y,c,r;
	if(x==0)c=p/n;
	else c=(p-x)/n+1;
	y=c%2;
	if(y==1)
	{
		if(x==0)r=n;
		else r=x;
	}
	else r=n-x+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}

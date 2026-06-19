#include<bits/stdc++.h>
using namespace std;

int n,m,sum,a[105],res,r,x,y,mod;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	res=a[1];
	sort(a+1,a+sum+1);
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==res)
		{
			r=sum-i+1;
			break;
		}
	}
	x=r/n;
	if(r%n!=0)x++;
	mod=r%n;
	if(mod==0)
	{
		if(x%2==1)y=n;
		else y=1;
	}
	else
	{
		if(x%2==1)y=mod;
		else y=n-mod+1;
	}
	cout<<x<<" "<<y;
}

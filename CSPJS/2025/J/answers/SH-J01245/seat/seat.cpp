#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,score,prize;
bool cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1]={0};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==score)
		{
			prize=i;
			break;
		}
	}
	if(prize%n==0)
	{
		c=prize/n;
	}
	else
	{
		c=prize/n+1;
	}
	if(n%2==0)
	{
		if(prize%n==0)
		{
			r=n;
		}
		else
		{
			r=prize%n;
			r=n-r+1;
		}
	}
	else
	{
		if(prize%n==0)
		{
			r=n;
		}
		else
		{
			r=prize%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

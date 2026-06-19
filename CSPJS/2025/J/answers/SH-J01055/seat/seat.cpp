#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	if(a>b)
	{
		return true;
	}
	return false;
}
long long n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int id=a[1],p;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==id)
		{
			p=i;
			break;
		}
	}
	int x,y;
	x=(p+n-1)/n;
	if(p%(2*n)==0)
	{
		y=1;
	}
	else if(p%(2*n)==n)
	{
		y=n; 
	}
	else if(p%(2*n)<n)
	{
		y=p%n;
	}
	else
	{
		y=n-p%n+1;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}

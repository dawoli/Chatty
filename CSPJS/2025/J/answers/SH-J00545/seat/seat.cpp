#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],b,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)b=a[i];
	}
	sort(a+1,a+n*m+1);
	int tmp=n*m-(lower_bound(a+1,a+n*m+1,b)-a)+1;
	c=(tmp-1)/n+1;
	if(c&1)
	{
		r=(tmp-1)%n+1;
	}
	else
	{
		r=n-((tmp-1)%n+1)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m,c,r,t,cnt,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=1;
	s=n*m;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--)
	{
		if(a[i]!=t)	cnt++;
		else break;
	}
	c=(cnt+n-1)/n;
	cnt-=(c-1)*n;
	if(c%2==1)
	{
		r=cnt;
	}
	else r=n-cnt+1;
	cout<<c<<" "<<r;
	return 0;
}

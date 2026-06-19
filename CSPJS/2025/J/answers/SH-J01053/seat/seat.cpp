#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int s=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			s=i;
			break;
		}
	}
	int b1=s%(2*n);
	int b2=s/(2*n);
	if(b1<=n)
	{
		cout<<b2*2+1<<" "<<b1;
	}
	else
	{
		if(b1==0) b1=n;
		cout<<b2*2+2<<" "<<2*n+1-b1;
	}
	return 0;
}

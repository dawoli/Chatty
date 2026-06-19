#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,r;
int x,y;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			int t=n*m-i+1;
			if(t%n==0) x=t/n;
			else x=t/n+1;
			if(x%2==1) y=t%n;
			else y=(t+n-1)%n;
			if(y==0) y=n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define SoaringWings return 0;
#define N 1000000007
#define int unsigned long long
int n,sum=0;
vector<int> a,b;
inline int S(int l,int r)
{
	int x=0,y=0,z=0;
	for(int i=l;i<=r;i++)
	{
		x=a[i]%N+x%N;
		x%=N;
	}
	for(int i=l;i<=r;i++)
	{
		y=b[i]%N+y%N;
		y%=N;
	}	
	z=x*y;
	z%=N;
	return z;
}
signed main()
{
	cin>>n;
	a.resize(n+1);
	b.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			sum+=S(l,r);
			sum%=N;
		}
	}
	cout<<sum;
	SoaringWings
}

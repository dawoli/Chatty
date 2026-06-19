#include<bits/stdc++.h>
using namespace std;
int n,a[503],cnt;
bool cmp(int y,int z)
{
	return y<=z;
}
void solve1(int x,int y,int z,int mx)
{
	if(x==0)
	{
		if(z>2*mx)
		{
			cnt++;
			cnt%=998244353;
		}
		else
		{
		}
		return;
	}
	for(int i=y;i<=n-x+1;i++)
	{
		solve1(x-1,i+1,z+a[i],max(mx,a[i]));
	}
}
void solve2(int x)
{
	long long y=1,z=1,o=998244353;
	for(int i=1;i<=x;i++)
	{
		y*=(n-i+1);
		z*=i;
	}
	cnt=(y/z)%o;
	return ;
}
void solve(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		solve1(x-1,i+1,a[i],a[i]);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=500)
	{
		for(int i=3;i<=n;i++)
		{
			solve2(i);
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=3;i--)
	{
		solve(i);
	}
	cout<<cnt;
	return 0;
}

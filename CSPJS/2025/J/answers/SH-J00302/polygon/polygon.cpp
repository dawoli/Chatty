#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	int n;
	cin>>n;
	if(n<=3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int cnt=max({a,b,c});
		if(a+b+c>2*cnt)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	long long cnt=(n*(n-1)*(n-2)/6)%998244353;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=cnt;
		cnt=cnt*(n-i-2);
		cnt/=(i+3);
		cnt%=998244353; 
	}
	cout<<sum;
}

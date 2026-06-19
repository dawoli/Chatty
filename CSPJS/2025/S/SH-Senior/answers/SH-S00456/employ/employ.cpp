#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"ok\n";

int d[1000],n,m,to=1;
string s;
bool cmp(int a,int b)
{
	return a<b;
 } 
void solve()
{
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
	}	
	sort(d+1,d+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		if(d[i]==d[i-1])	to*=2;
		to=to%998244353;
	}
	cout<<to;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)
	{
		solve();
	}
 	return 0;
}


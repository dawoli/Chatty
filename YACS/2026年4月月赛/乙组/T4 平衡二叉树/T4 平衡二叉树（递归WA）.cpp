// Problem URL: https://iai.sh.cn/problem/659
// Finish Time: 2026/5/16 16:22:44 WA 10 pts
// Start Time: 2026/5/16 15:59:39

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int n,f[5001]={0,1};
int work(int x)
{
	if(x==0)return 1;
	if(f[x]!=0)return f[x];
	int ans;
	x--;
	if(x%2==0)
	{
		int a=work(x/2);
		ans=a*a%MOD;
	}
	else ans=work(x/2)*work(x-x/2)*2%MOD;
	return f[x]=ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	cout<<work(n);
	return 0;
}
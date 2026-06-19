// Problem URL: https://www.luogu.com.cn/problem/P15800
// Finish Time: 2026/3/22 11:39:57 AC
// Finish Time: 2026/3/22 11:02:51 WA 40pts
// Start Time: 2026/3/22 10:55:39

#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
typedef long long int ll;
int n,a[MAXN],b[MAXN];
ll f[2*MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=n;i>=1;i--)
		f[i]=max(f[i+1],a[i]+f[i+max(1,b[i])]);
	cout<<f[1];
	return 0;
}
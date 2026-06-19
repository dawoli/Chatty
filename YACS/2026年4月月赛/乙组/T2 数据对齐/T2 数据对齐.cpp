// Problem URL: https://iai.sh.cn/problem/1221
// Finish Time: 2026/5/4 17:41:40 AC
// Finish Time: 2026/5/4 17:36:42 WA
// Start Time: 2026/5/4 17:17:07

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,a[300005],b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>b;
		if(b>=a[n])
		{
			cout<<b-a[n]<<"\n";
			continue;
		}
		if(b<=a[1])
		{
			cout<<a[1]-b<<"\n";
			continue;
		}
		int *p=lower_bound(a+1,a+n+1,b);
		if(*p==b)cout<<"0\n";
		else
		{
			int *sp=p-1;
			cout<<min(*p-b,b-*sp)<<"\n";
		}
	}
	return 0;
}
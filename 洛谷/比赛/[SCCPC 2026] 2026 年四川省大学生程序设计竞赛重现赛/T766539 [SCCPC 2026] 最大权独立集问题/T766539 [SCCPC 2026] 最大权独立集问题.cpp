// Problem URL: https://www.luogu.com.cn/problem/T766539?contestId=330334
// Finish Time: 2026/6/21 15:42:44 AC
// Start Time: 2026/6/21 15:03:44

#include <iostream>
using namespace std;
typedef long long ll;
void solve()
{
	int n;
	cin>>n;
	ll s0=0,s1=0;
	for(int i=0;i<n;++i)
	{
		int w;
		cin>>w;
		if(__builtin_popcount(w)%2==0)
			s0+=w;
		else
			s1+=w;
	}
	cout<<max(s0,s1)<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
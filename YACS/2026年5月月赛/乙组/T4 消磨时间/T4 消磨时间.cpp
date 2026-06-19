// Problem URL: https://iai.sh.cn/problem/1243
// Finish Time: 2026/5/23 12:07:52 RE 50pts
// Start Time: 2026/5/23 11:52:27

#include <iostream>
using namespace std;
constexpr int MAXN=100000008;
int n,W,v[MAXN],f[MAXN];
int main()
{
	cin>>n>>W;
	for(int i=1; i<=n; i++)
		cin>>v[i];
	for(int i=1; i<=n; i++)
		for(int l=W; l>=v[i]; l--)
			if(f[l-v[i]]+v[i]>f[l]) f[l]=f[l-v[i]]+v[i];
	cout<<f[W];
	return 0;
}
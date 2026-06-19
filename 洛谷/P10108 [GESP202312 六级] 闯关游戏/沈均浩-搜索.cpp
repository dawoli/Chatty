#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[20010],f[20010];
int dfs(int x)
{
	if(f[x]!=-0x3f3f3f3f) return f[x];
	if(x>=n) return 0;
	int cnt=-0x3f3f3f3f;
	for(int i=0;i<m;i++)
	{
		cnt=max(cnt,dfs(x+a[i])+b[x]);
	}
	return f[x]=cnt;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) f[i]=-0x3f3f3f3f;
	cout<<dfs(0);
	return 0;
}
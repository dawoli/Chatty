// Problem URL: https://www.luogu.com.cn/problem/P4551
// Finish Time: 2026/6/20 10:21:01 AC
// Start Time: 2026/6/20 09:29:42

#include <bits/stdc++.h>
#define to first
#define w second
#define pii pair<int,int>
#define MAXN 100005
using namespace std;
typedef long long int ll;
int n,trie[MAXN*31][2],tot=0,s[MAXN],ans=INT_MIN;
vector<pii> e[MAXN];
void dfs(int x,int fa)
{
	for(int i=0;i<e[x].size();i++)
	{
		int nxt=e[x][i].to;
		if(nxt==fa) continue;
		s[nxt]=s[x]^e[x][i].w;
		dfs(nxt,x);
	}
}
void insert(int val)
{
	int x=0;
	for(int i=1<<30;i;i>>=1)
	{
		int a=bool(val&i);
		if(!trie[x][a]) trie[x][a]=++tot;
		x=trie[x][a];
	}
}
int find(int val)
{
	int ans=0,x=0;
	for(int i=1<<30;i;i>>=1)
	{
		int a=bool(val&i);
		if(trie[x][!a]) ans+=i,x=trie[x][!a];
		else x=trie[x][a];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int fr,to,w;
		cin>>fr>>to>>w;
		e[fr].push_back({to,w});
		e[to].push_back({fr,w});
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)
		insert(s[i]);
	for(int i=1;i<=n;i++)
		ans=max(ans,find(s[i]));
	cout<<ans;
	return 0;
}
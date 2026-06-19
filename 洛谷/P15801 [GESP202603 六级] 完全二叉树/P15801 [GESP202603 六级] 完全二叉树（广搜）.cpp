// Problem URL: https://www.luogu.com.cn/problem/P15801
// Finish Time: 2026/3/28 16:59:43 AC
// Start Time: 2026/3/28 16:47:51

#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef long long int ll;
int n;
pair<int,int> t[100005];
bool isct(int u)
{
	queue<int> q;
	q.push(u);
	bool flag=false;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		if(v==0)
		{
			flag=true;
			continue;
		}
		if(flag) return false;
		q.push(t[v].l);
		q.push(t[v].r);
	}
	return true;
}
int dfs()
{
	int ans=0,top=1,k[100005]={0,1};
	while(top)
	{
		int u=k[top--];
		if(isct(u)) ans++;
		if(t[u].l) k[++top]=t[u].l;
		if(t[u].r) k[++top]=t[u].r;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i].l>>t[i].r;
	cout<<dfs();
	return 0;
}
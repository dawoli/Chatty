// Problem URL: https://ww.luogu.com.cn/P3065
// Start Time: 2026/6/25 07:38:17

#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int son[27],end;
}N[300010];
vector<int> E[27];
int n,cnt=1,ind[30010],ans_sum,used[27][27];
string ans[30010],s[30010];
void insert(string s)
{
	int now=1;
	for(int i=0;i<s.length();i++)
	{
		if(!N[now].son[s[i]-'a']) N[now].son[s[i]-'a']=++cnt;
		now=N[now].son[s[i]-'a'];
	}
	N[now].end++;
}
int work(string s)
{
	int now=1;
	for(int i=0;i<s.length();i++)
	{
		int t=s[i]-'a';
		if(N[now].end) return 0;
		for(int j=0;j<26;j++)
		{
			if(N[now].son[j]&&t!=j)
			{
				E[t].push_back(j);
				ind[j]++;
			}
		}
		now=N[now].son[t];
	}
	return 1;
}
int check()
{
	queue<int> q;
	for(int i=0;i<26;i++) if(!ind[i]) q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<E[u].size();i++)
		{
			ind[E[u][i]]--;
			if(!ind[E[u][i]]) q.push(E[u][i]);
		}
	}
	for(int i=0;i<26;i++) if(ind[i]) return 0;
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		insert(s[i]); 
	}
	for(int i=1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		memset(ind,0,sizeof(ind));
		for(int j=0;j<27;j++) E[j].clear();
		if(!work(s[i])) continue;
		if(check()) ans[++ans_sum]=s[i];
	}
	cout<<ans_sum<<endl;
	for(int i=1;i<=ans_sum;i++) cout<<ans[i]<<endl;
	return 0;
}

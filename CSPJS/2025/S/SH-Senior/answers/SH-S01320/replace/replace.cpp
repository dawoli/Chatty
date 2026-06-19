#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=5e6+5,b1=2952,p1=998244353;
struct T{int a;};
struct Q{T x;int id;};
char s1[M],s2[M];
int ch[M][26],fail[M],stk[M],ans[N];
vector<T>vec[M];
vector<int>g[M];
vector<Q>qq[M];
unordered_map<int,int>mp;
T h1[N];
void mrg(T&a,char b)
{
	a.a=(a.a*b1+b)%p1;
}
void dfs(int u)
{
	for(T x:vec[u])
	{
		mp[x.a]++;
	}
	for(Q x:qq[u])
	{
		ans[x.id]+=mp[x.x.a];
	}
	for(int v:g[u])dfs(v);
	for(T x:vec[u])
	{
		mp[x.a]--;
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s1+1>>s2+1;
		int l=strlen(s1+1);
		for(int j=1;j<=l;j++)s1[j]-='a';
		for(int j=1;j<=l;j++)s2[j]-='a';
		h1[i].a=0;
		int p=l+1;
		for(int j=1;j<=l;j++)
		{
			if(s1[j]!=s2[j])
			{
				p=j;
				break;
			}
		}
		for(int j=p;j<=l;j++)
		{
			mrg(h1[i],s1[j]);
			mrg(h1[i],s2[j]);
		}
		int now=0;
		for(int j=1;j<=l;j++)
		{
			if(!ch[now][s1[j]])ch[now][s1[j]]=++cnt;
			now=ch[now][s1[j]];
		}
		vec[now].push_back(h1[i]);
	}
	int head=1,tail=0;
	for(int i=0;i<26;i++)
	{
		if(ch[0][i])stk[++tail]=ch[0][i];
	}
	while(head<=tail)
	{
		int u=stk[head++];
		for(int i=0;i<26;i++)
		{
			if(ch[u][i])
			{
				int v=ch[u][i];
				fail[v]=ch[fail[u]][i];
				stk[++tail]=v;
			}
			else ch[u][i]=ch[fail[u]][i];
		}
	}
	for(int i=1;i<=cnt;i++)g[fail[i]].push_back(i);
	for(int i=1;i<=q;i++)
	{
		cin>>s1+1>>s2+1;
		int l=strlen(s1+1);
		for(int j=1;j<=l;j++)s1[j]-='a';
		for(int j=1;j<=l;j++)s2[j]-='a';
		int p1=l+1,p2=0;
		for(int j=1;j<=l;j++)
		{
			if(s1[j]!=s2[j])
			{
				p1=j;
				break;
			}
		}
		for(int j=1;j<=l;j++)if(s1[j]!=s2[j])p2=j;
		int now=0;
		T h2={0};
		for(int j=1;j<=l;j++)
		{
			now=ch[now][s1[j]];
			if(j>=p1)
			{
				mrg(h2,s1[j]);
				mrg(h2,s2[j]);
			}
			if(j>=p2)qq[now].push_back({h2,i});
		}
	}
	dfs(0);
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}

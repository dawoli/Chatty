#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int c,id;
	bool operator<(Node& x)
	{
		return c<x.c;
	}
}c[100005];
int n,m,t;
int a[100005];
int e[20];
bool b[20][200005];
int x[4];
int d[100005];
long long ans,sum,cc;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>c[i].c;
		c[i].id=i;
	}
	sort(c+1,c+m+1);
	int k=0,kk=1;
	e[k]=kk;
	while(kk<n)
	{
		k++;
		kk*=2;
		e[k]=kk;
	}
	for(int i=1;i<=k;i++)
	{
		string s;
		cin>>s;
		int len=s.size();
		for(int j=0;j<len;j++)
		{
			b[i][j]=s[j]-'0';
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		memset(d,-1,sizeof(d));
		ans=0;
		cc=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=cc+1;j<=c[i].c;j++)
			{
				d[j]=a[j]^x[i%4];
			}
			cc=c[i].c;
			int p=0;
			while(e[p]>=cc)p++;
			if(c[i].c!=c[i-1].c)
			{
				sum=e[p];
			}
			ans^=(sum*c[i].id);
		}
		cout<<ans<<endl;
	}
	return 0;
}

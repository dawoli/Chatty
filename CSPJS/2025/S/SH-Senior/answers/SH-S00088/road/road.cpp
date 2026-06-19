#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
	bool operator>(const node &a) const{return w>a.w;}
} ;
long long n,m,k,c[11],r[11][10001],cnt=0,ans;
int fa[10001];
int find(int p)
{
	if(fa[p]==p) return p;
	else
	{
		fa[p]=find(fa[p]);
		return fa[p];
	}
}
priority_queue<node,vector<node>,greater<node> > q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		node p;
		cin>>p.u>>p.v>>p.w;
		q.push(p);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>r[i][j];
		}
	}
	while(!q.empty())
	{
		node p=q.top();
		q.pop();
		if(fa[find(p.u)]!=fa[find(p.v)])
		{
			fa[find(p.u)]=fa[find(p.v)];
			cnt++;
			ans+=p.w;
		}
		//cout<<cnt<<endl;
		if(cnt==n-1) break;
	}
	cout<<ans<<endl;
	return 0;
}

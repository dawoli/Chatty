#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k,c[19],ds[19][10009],fa[100009];

struct edge
{
	ll u,v,w;
	bool operator<(const edge&a)const
	{
		return w<a.w;
	}
} es[11000009];

ll find(ll x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}

void unite(ll x,ll y)
{
	ll fax=find(x);
	ll fay=find(y);
	fa[fax]=fay;
	return;
}

bool check(ll x,ll y)
{
	if(find(x)==find(y))
		return true;
	return false;
}

ll kruscal()
{
	ll res=0, cnt=0;
	sort(es+1,es+m+1);
	for(int i=1;i<=m;i++)
	{
		if(!check(es[i].u,es[i].v))
			unite(es[i].u,es[i].v), cnt++, res+=es[i].w;
		if(cnt==n-1) break;
	}
	return res;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%lld %lld %lld",&es[i].u,&es[i].v,&es[i].w);
	bool flag=true;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&ds[i][j]);
		}
		if(c[i]!=0)
			flag=false;
	}
//	printf("\\\ \n");
	if(k==0)
	{
//		printf("\\\ \n");
		printf("%lld\n",kruscal());
	}
	else if(flag)
	{
		for(ll i=1;i<=k;i++)
		{
//			printf("%d\n",i);
			for(ll j=1;j<=n;j++)
			{
//				printf("%lld\n",n);
				for(ll l=j+1;l<=n;l++)
				{
					es[++m]=(edge){j,l,ds[i][j]+ds[i][l]};
				}
//				printf("%d\n",j);
			}
//			for(int j=1;j<=1e6;j++);
		}
//		printf("\\\ \n");
		printf("%lld\n",kruscal());
	}
}

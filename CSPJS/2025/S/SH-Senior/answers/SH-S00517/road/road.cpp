#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0;
long long f[10004];
struct road{
	int u,v,w;
};
road r[2000006];
void chushi()
{
	for(int i=1;i<=n;i++)f[i]=i; 
}
int get(int q)
{
	if(f[q]==q)return q;
	return get(f[q]);
}
void conn(int z,int y)
{
	f[get(z)]=get(y);
}
bool isconn(int z,int y)
{
	if(get(z)==get(y))return 1;
	else return 0;
}
bool cmp(road&y,road&z)
{
	return y.w<z.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	chushi();
	if(k==0)
	{
		sort(r+1,r+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			if(!isconn(r[i].u,r[i].v)) {
				conn(r[i].u,r[i].v);
				ans+=r[i].w;
			}
		}
		cout<<ans;return 0;
	}
	int z[10004][11];
	for(int i=1;i<=k;i++)
	{
		cin>>z[0][i];
		for(int j=1;j<=n;j++)
		{
			cin>>z[j][i];
		}
	}
	int g=m+1;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long q=3e9;
			for(int t=1;t<=k;t++)if(q>z[i][t]+z[j][t]+z[0][t])q=z[i][t]+z[j][t]+z[0][t];
			r[g].u=i;
			r[g].v=j;
			r[g].w=q;
			g++;
		}
	}
	sort(r+1,r+g,cmp);
	for(int i=1;i<g;i++)
	{
		if(!isconn(r[i].u,r[i].v)) {
			conn(r[i].u,r[i].v);
			ans+=r[i].w;
		}
	}
	cout<<ans;
	return 0;
} 

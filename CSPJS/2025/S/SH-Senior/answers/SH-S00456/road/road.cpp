#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"ok\n";
#define endl "\n"
#define int long long
const int N=1e4+7,M=2e7+7,S=1e3+7;
struct edge{
	int u,v,w;
}; 
edge rd[M];

int f[N],d[N];
int n,m,k,a,b,c,kk,to=0;
int mp[N];
int mp2[S][S];

int find(int x){
	if(f[x]==x)	return x;
	return f[x]=find(f[x]);
}
bool cmp(edge i,edge j)
{
	return i.w<j.w;
}

//void solve2()
//{
//	memset(mp2,1e9+7,sizeof(mp2));
//	for(int i=1;i<=n;i++)
//	{
//		f[i]=i;
//	}
//	
//	for(int i=1;i<=m;i++)
//	{
//		cin>>a>>b>>c;
//		mp2[min(a,b)][max(a,b)]=min(c,mp2[min(a,b)][max(a,b)]);
//	}
//	for(int i=1;i<=k;i++)
//	{
//		cin>>mp[0];
//		
//		for(int j=1;j<=n;j++)
//		{
//			cin>>mp[j];
//		} 
//		for(int itu=1;itu<n;itu++)
//		{
//			for(int itv=itu+1;itv<=n;itv++)
//			{
//				kk=mp[itv]+mp[itu]+mp[0];
//				mp2[itu][itv]=min(kk,mp2[itu][itv]);
//			}
//		}
//	}
//	int cnt=1;
//	for(int i=1;i<n;i++)
//	{
//		for(int j=i+1;j<=n;i++){
//			rd[cnt]=(edge){i,j,mp2[i][j]};
//			cnt++;
//		}	
//	}
//	
//	sort(rd+1,rd+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++)
//	{
//		if(find(rd[i].u)!=find(rd[i].v))
//		{
//			to+=rd[i].w;
//			f[rd[i].u]=rd[i].v;
//			d[rd[i].u]=rd[i].w;
//		}
//	}
//	debug
//	cout<<to;
//}

void solve()
{
	
//	debug
//	if(n<S && k>=1){
//		solve2();
//		
//		return;
//	}
	
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		rd[i]=(edge){min(a,b),max(a,b),c};
	}
	sort(rd+1,rd+m+1,cmp);
	int mm;
	for(int i=1;i<=m;i++)
	{
		if(find(rd[i].u)!=find(rd[i].v))
		{
			to+=rd[i].w;
			f[rd[i].u]=rd[i].v;
			mm=rd[i].w;
			d[rd[i].u]=rd[i].w;
		}
	}
	if(k==0){
		cout<<to;
		return;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>mp[0];
		
		for(int j=1;j<=n;j++)
		{
			cin>>mp[j];
		} 
		if(mp[0]>=mm)	continue; 
		for(int itu=1;itu<n;itu++)
		{
			for(int itv=itu+1;itv<=n;itv++)
			{
				kk=mp[itv]+mp[itu]+mp[0];//liangdianju
				
				if(kk<d[itv] || kk<d[itu])
				{
					if(d[itu]>d[itv])
					{
						d[itu]=kk;
					}
					else if(d[itv]>d[itu]){
						d[itv]=kk;
					} 
					else{
						if(itv>itu)
						{
							d[itv]=kk;
						}
						else{
							d[itu]=kk;
						}
					}
				}
			}
		}
	}
	to=0;
	for(int i=1;i<=n;i++)
	{
		to+=d[i];
	}
	cout<<to;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)
	{
		cin>>n>>m>>k;
		solve();
	}
 	return 0;
}


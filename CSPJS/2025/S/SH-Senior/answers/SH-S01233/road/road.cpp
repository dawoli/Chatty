#include <bits/stdc++.h>
using namespace std;
struct Node{
	int f,t;
	long long d;
	int vis;
};
struct vil{
	long long fee,d[10005];
}v[15];
int n,m,k; 
long long ans=1e18;
long long a[10001][10001];
int f[15001];
vector<Node> ee;
bool cmp(Node x,Node y) { return x.d<y.d; }
int find(int x) { return x==f[x] ? x : f[x]=find(f[x]); }
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y) f[x]=y;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(a[x][y]!=0&&a[x][y]<=z) continue;
		a[x][y]=a[y][x]=z;
		ee.push_back({x,y,z,0});
	}
	for(int l=1;l<=k;l++)
	{
		cin>>v[l].fee;
		for(int j=1;j<=n;j++) 
		{
			cin>>v[l].d[j];
			ee.push_back({j,n+l,v[l].d[j],l});
		}
	}
	sort(ee.begin(),ee.end(),cmp);
	for(int i=0;i<=(1<<k)-1;i++)
	{
		for(int j=1;j<=n+k;j++) f[j]=j;
		long long res=0; 
		for(int j=1;j<=k;j++) if(i&(1<<(j-1))) res+=v[j].fee;
		for(auto it : ee)
		{
			int x=it.f,y=it.t;
			if(find(x)==find(y)||(it.vis!=0&&!(i&(1<<(it.vis-1))))) continue;
			merge(x,y);
			res+=it.d;
			if(res>ans) break;
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
} 


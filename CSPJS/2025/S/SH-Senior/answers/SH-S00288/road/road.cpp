#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=1e6+5;
int u[M],v[M],w[M];
int n,m,k,a[15][N],co[15];
vector<int> p;
int q[M],e[M],l,r,c;
long long ans,sum;
int fa[N],sz[N];

int get(int x){
	if(x<=m)return w[x];
	x-=m+1;return a[x/n+1][x%n+1];
}

bool cmpe(int x,int y){
	return get(x)<get(y);
}

int gf(int x){
	return (fa[x]==x?x:fa[x]=gf(fa[x]));
}

void merge(int x,int y,int z){//cerr<<x<<" "<<y<<" "<<z<<"\n";
	x=gf(x),y=gf(y);if(x==y)return;//cerr<<x<<" "<<y<<"\n";
	if(sz[x]<sz[y])swap(x,y);fa[y]=x,sz[x]+=sz[y];sum+=z;
}

bool cmp(int x,int y){
	return w[x]<w[y];
}

void solve(){
	cin>>n>>m>>k;int x,y;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i],q[i]=i;
	for(int i=1;i<=k;i++){cin>>co[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}sort(q+1,q+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		x=q[i];if(gf(u[x])!=gf(v[x]))
			merge(u[x],v[x],w[x]),p.push_back(q[i]),e[++c]=q[i];
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			e[++c]=m+1+(i-1)*n+j-1;
	sort(e+1,e+c+1,cmpe);ans=1e18;
	for(int i=0;i<(1<<k);i++){sum=0;
		// cerr<<"now: "<<i<<"\n";
		for(int j=1;j<=n+k;j++)fa[j]=j,sz[j]=1;
		for(int j=1;j<=c;j++){
			if(e[j]<=m)merge(u[e[j]],v[e[j]],w[e[j]]);
			else{
				x=(e[j]-m-1)/n+1,y=(e[j]-m-1)%n+1;
				if(!((i>>(x-1))&1))continue;
				merge(x+n,y,a[x][y]);
			}
		}for(int j=0;j<k;j++)
			if((i>>j)&1)sum+=co[j+1];
		ans=min(ans,sum);
	}cout<<ans<<"\n";
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1;while(T--)solve();
}
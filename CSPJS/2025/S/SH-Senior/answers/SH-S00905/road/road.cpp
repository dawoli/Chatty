#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N=1e4+109,M=1e6+9,K=19,PW2K=1109;
const ll INF=1e17;
int n,m,k;
struct Edge{int u,v;ll w;} e0[M],e[PW2K][N],tmp[PW2K][N],prest[K][N];
bool cmpE(const Edge &a,const Edge &b){return a.w<b.w;};
int p[N],sz[N];
ll ans=INF;int cnttmp=0;
ll a[K][N],c[K];

int rt(int x){
	if(x==p[x])return x;
	return p[x]=rt(p[x]);
}
ll kruskal1(){
	for(int i=1;i<=n+k;i++)p[i]=i,sz[i]=1;
	int cnt=0;ll res=0;cnttmp=0;
	for(int i=1;i<=m&&cnt!=n-1;i++){
		int u=e0[i].u,v=e0[i].v;ll w=e0[i].w;
		int rtu=rt(u),rtv=rt(v);
		if(rtu==rtv)continue;
		if(sz[rtu]<sz[rtv])p[rtu]=rtv;
		else p[rtv]=rtu;
		res+=w,cnt++;
		tmp[0][++cnttmp]=e0[i];
	}
	return res;
}
ll kruskal2(int s,int ppc){
	for(int i=1;i<=n+k;i++)p[i]=i,sz[i]=1;
	int cnt=0;ll res=0;cnttmp=0;
	for(int i=1;i<=2*n-1+ppc&&cnt!=n+ppc-1;i++){
		int u=e[s][i].u,v=e[s][i].v;ll w=e[s][i].w;
		int rtu=rt(u),rtv=rt(v);
		if(rtu==rtv)continue;
		if(sz[rtu]<sz[rtv])p[rtu]=rtv;
		else p[rtv]=rtu;
		res+=w,cnt++;
		tmp[s][++cnttmp]=e[s][i];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e0[i].u>>e0[i].v>>e0[i].w;
	sort(e0+1,e0+m+1,cmpE);
	ans=kruskal1();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++){
			prest[i][j].u=0,prest[i][j].v=j,prest[i][j].w=a[i][j];
		}
		sort(prest[i]+1,prest[i]+n+1,cmpE);
	}
	for(int s=1;s<(1<<k);s++){
		int ppc=0;
		for(int i=0;i<k;i++){
			bool u=(1<<i)&s;
			ppc+=u;
		}
		for(int i=k-1;i>=0;i--){
			int mask=1<<i;
			if(mask&s){
				for(int j=1;j<n+ppc-1;j++)e[s][j]=tmp[s^mask][j];
//				for(int j=n+ppc;j<2*n+ppc;j++)
//					e[s][j].u=n+ppc,e[s][j].v=j-ppc-n+1,e[s][j].w=a[i+1][j-ppc-n+1];
				for(int j=n+ppc;j<2*n+ppc;j++){
					e[s][j]=prest[i+1][j-ppc-n+1];
					e[s][j].u=n+ppc;
				}
				int cnttmp=0;
				for(int x=1,y=n+ppc;x<n+ppc-1||y<2*n+ppc;){
					if(x<n+ppc-1&&e[s][x].w<=e[s][y].w)tmp[s][++cnttmp]=e[s][x++];
					else tmp[s][++cnttmp]=e[s][y++];
				}
				for(int j=1;j<2*n+ppc;j++)e[s][j]=tmp[s][j];
				break;
			}
		}
//		cout<<s<<endl;
//		for(int i=1;i<2*n+ppc;i++)
//			cout<<e[s][i].u<<" "<<e[s][i].v<<" "<<e[s][i].w<<endl;
//		sort(e[s]+1,e[s]+2*n+ppc,cmpE);
		ll res=kruskal2(s,ppc);
		for(int i=0;i<k;i++){
			int mask=1<<i;
			if(mask&s)res+=c[i+1];
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20009;
const int M=1000009;
const int K=12;
const ll INF=1e17+9;
int n,m,k,nE;
int c[K],d[K];
ll a[K][N];
struct Edge{
	int u,v;
	ll w;
	bool flg;
}e[2][2*M];
bool cmp(const Edge&A,const Edge&B){
	return A.w<B.w;
}
int id[N];
int root(int u){
	if(id[u]==u) return u;
	id[u]=root(id[u]);
	return id[u];
}
ll ans=0,bst=0;
int now=0;
void krustal(){
	ans=0;
	sort(e[now]+1,e[now]+nE+1,cmp);
	for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1;i<=nE;i++){
		int u=e[now][i].u,v=e[now][i].v,w=e[now][i].w;
		int ru=root(u),rv=root(v);
		if(ru==rv) continue;
		ans+=w;
		id[ru]=rv;
		e[now][i].flg=1;
	}
}
void chan(){
	int t=0;
	for(int i=1;i<=nE;i++){
		if(!e[now][i].flg) continue;
		e[1-now][++t]=e[now][i];
	}
	now=1-now;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[0][i].u>>e[0][i].v>>e[0][i].w;
	for(int j=1;j<=k;j++) a[j][n+1]=INF,d[j]=n+1;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
			if(a[j][i]<a[j][d[j]]) d[j]=i;
		}
	}
	nE=m;
	krustal();
	chan();
	bst=ans;
	if(k==0){
		cout<<bst<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		if(i!=1){
			nE=0;
			for(int j=1;j<n;j++) nE++,e[now][nE]=e[1-now][nE];
		}
		for(int j=1;j<=n;j++){
			if(d[i]==j) continue;
			e[now][++nE]=(Edge){d[i],j,a[i][j]};
		}
		krustal();
		if(ans+c[i]+a[i][d[i]]>=bst) continue;
		bst=ans+c[i]+a[i][d[i]];
		chan();
	}
	cout<<bst<<endl;
	return 0;
} 

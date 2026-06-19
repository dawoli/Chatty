#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll V=1e4+100,E=1e6+10; 
ll n,m,k;
struct edge{
	int u,v,w;
}e[E*3];
int nE;
ll p[V];
int find(ll x){
	if(p[x]==x) return x;
	p[x]=find(p[x]);
	return p[x];
}
void add(int u,int v,int w){
	e[++nE]=(edge){u,v,w};
}
struct sedge{
	int u,v,w;
}se[E*2];
bool cmp(sedge &a,sedge &b){
	return a.w<b.w;
}
ll ks(int nV){
	for(int i=1;i<V;i++) p[i]=i;
	int t=nE;
	for(int i=1;i<=t;i++){
		se[i]=(sedge){e[i].u,e[i].v,e[i].w};
	}
	sort(se+1,se+t+1,cmp);
	ll cnt=0,ans=0;
	for(int i=1;cnt<nV-1 && i<=t;i++){
		int u=se[i].u;
		int v=se[i].v;
		int uu=find(u),vv=find(v);
		if(uu==vv) continue;
		//cout<<u<<" "<<v<<" "<<se[i].w<<"\n";
		p[uu]=vv;
		ans+=se[i].w;
		cnt++;
	}
	return ans;
}
int c[20],a[V][20];
bool to_use[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k; 
	nE=m;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool cA=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) cA=false;
		for(int j=1;j<=n;j++) cin>>a[j][i];
	}
	if(k==0) cout<<ks(n);
	else if(cA){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				add(n+i,j,a[j][i]);
			}
		}
		cout<<ks(n+k);
	}
	else{
		int mx=0;
		for(int i=1;i<=k;i++){
			if(c[i]>c[mx]) mx=i;
		}
		ll toadd=0;
		for(int i=1;i<=k;i++){
			if(i==mx) continue;
			toadd+=c[i];
			for(int j=1;j<=n;j++){
				add(n+i,j,a[j][i]);
			}
		}
		ll ans=ks(n+k-1)+toadd;
		toadd+=c[mx];
		for(int j=1;j<=n;j++){
			add(n+mx,j,a[j][mx]);
		}
		ans=min(ks(n+k)+toadd,ans);
		cout<<ans;
	}
	return 0;
}
/*
4 5 1
1 4 6
2 3 7
4 2 5
1 2 3
4 3 4
0 2 3 4 0
-static-libgcc
*/

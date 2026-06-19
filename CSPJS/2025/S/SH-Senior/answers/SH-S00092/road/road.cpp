#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,c[15],uc[15][10005];
struct ro{
	ll v,w;
};
ll f[10005];
vector<ro> a[10005];
queue<ro> q;
void bfsk0(){
	f[1]=0;
	for(int i=0;i<a[1].size();i++){
		q.push(a[1][i]);
		f[a[1][i].v]=a[1][i].w;
	}
	while(q.size()){
		ll vx=q.front().v,wx=q.front().w;
		q.pop();
		for(int i=0;i<a[v].size();++i){
			if(f[a[v][i].v]>wx+a[v][i].w){
				f[a[v][i].v]=wx+a[v][i].w;
				q.push({a[v][i].v,f[a[v][i].v]});
			}
		}
		if(q.empty()) cout<<wx<<endl;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>uc[i][j];
	}
	if(k==0) bfsk0();
	else{
		
	}
	return 0;
}

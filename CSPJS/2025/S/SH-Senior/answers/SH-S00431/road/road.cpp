#include<bits/stdc++.h>
#define to first
#define w second
#define int long long
using namespace std;
int n,m,k,a[11][1000001];
vector<int>g[1000001];
struct ty{
	int u,v,w;
}t[1000001];
bool f[1000001];
bool cmp(const ty x,const ty y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>a[i][0];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	sort(t+1,t+m+1,cmp);
	int cnt=0,sum=0;
	for(int i=1;cnt<n;++i){
		if((f[t[i].u]^f[t[i].v])||(!cnt)){
			f[t[i].u]=f[t[i].v]=1;
			cnt++;
			sum+=t[i].w;
		}
	}
	cout<<sum;
	return 0;
}

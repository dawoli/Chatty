#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,m,k;
int ans=0;
int f[100005];
struct node{
	int u,v,w;
};
node way[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>way[i].u>>way[i].v>>way[i].w;
	}
	int node=m;
	int cnt=n;
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		cnt++;
		for(int i=1;i<=n;i++){
			int b;
			cin>>b;
			if(b==0){
				f[cnt]=i;
			}
			else{
				node++;
				way[node].u=cnt;
				way[node].v=i;
				way[node].w=b;
			}
		}
	}
	sort(way+1,way+node+1,cmp);
	for(int i=1;i<=node;i++){
		if(find(way[i].u)!=find(way[i].v)){
			f[way[i].v]=find(way[i].u);
			ans+=way[i].w;
		}
	}
	cout<<ans;
	return 0;
}

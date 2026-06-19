#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,d;
struct node{
	int u,v,w;
};
vector<node> s;
ll c[100];
ll a[100][10005];
int f[10005];
int ans=0;
int find(int x){
	if(x!=f[x]){
		f[x]=find(f[x]);
	}
	return f[x];
}
int hb(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>n>>m>>d;
	for(int i=1;i<=n+d;i++) f[i]=i;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s.push_back({u,v,w});
	}
	for(int i=1;i<=d;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			s.push_back({n+i,j,a[i][j]});
		}
	}
	sort(s.begin(),s.end(),cmp);
	for(node x:s){
		if(find(x.u)!=find(x.v)){
			hb(x.u,x.v);
			ans+=x.w;
		}
	}
	cout<<ans;
	return 0;
}


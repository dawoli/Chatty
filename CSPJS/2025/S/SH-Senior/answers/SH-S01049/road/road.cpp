#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10,inf=1e9+10;
int n,m,k,c[N],f[M+N],sum=0;
//bool usd[N];
struct edge{
	int u,v,w;
}eg[N+M];
vector <edge> v;
int ff(int a){
	int r=a;
	while(r!=f[r]){
		r=f[r];
	}
	while(f[a]!=r){
		int t=f[a];
		f[a]=r;
		a=t;
	}
	return r;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k; 
	int u,v,w;
	//cin>>u>>v>>w;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		eg[i].v=v;
		eg[i].u=u;
		eg[i].w=w;
		f[i]=i;
	}
	//cin>>c[j];
	int pp;
	for(int j=1;j<=m;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>pp;
			//v.push_back({i,j,pp});
		}
	}
	sort(eg+1,eg+m+1,cmp);
	for(int i=1;i<=n;i++){
		//cout<<ff(eg[i].u)<<" "<<ff(eg[i].v)<<"\n";
		if(ff(eg[i].u)!=ff(eg[i].v)){
			sum+=eg[i].w;
			f[v]=u;
		}
	}
	cout<<sum;
	return 0;
}
/*
emm不知道咋写 
想打部分分结果忘记kruskal怎么写了
自己搓了一个 
我是这个（大拇指）

*/

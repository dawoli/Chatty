#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=1e4+10;

struct Edge{
	int f,t,v;
}e[M];

struct city{
	int cost,v[N];
}c[15];

bool cmp(Edge a,Edge b){
	return a.v<b.v;
}

int fa[N];

int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool fla=true;
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>e[i].f>>e[i].t>>e[i].v;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;++i){
		cin>>c[i].cost;
		for(int j=1;j<=n;++j){
			cin>>c[i].v[j];
			if(c[i].cost!=0){
				fla=false;
			}
		}
	}
	if(k==0){
		for(int i=1;i<=m;++i){
			int a=find(e[i].f),b=find(e[i].t);
			if(a!=b){
				fa[b]=a;
				ans+=e[i].v;
			}
		}
		cout<<ans;
	}
//	else if(fla){
//		for(int p=1;p<=k;++p){
//			for(int i=1;i<=n;++i){
//				for(int j=1;j<=n&&j!=i;++j){
//					
//				}
//			}
//		}
//		sort(e+1,e+1+m,cmp);
//		for(int i=1;i<=m;++i){
//			int a=find(e[i].f),b=find(e[i].t);
//			if(a!=b){
//				
//			}
//		}
//	}
	return 0;
}

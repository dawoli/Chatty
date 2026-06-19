#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=10005;
const int M=1e6+5;
int n,m,k,ans=0,tot,num;
int fa[N],c[N],a[15][N];
vector<int> g[N<<1];
struct node{
	int u,v,w;
	bool operator < (const node& x) const{
		return w<x.w;
	}
}e[M<<1],ee[M];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int Kruskal(){
	sort(e+1,e+tot+1);
	for(int i=1;i<=num;i++){
		fa[i]=i;
	}
	int cnt=0,res=0;
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fv]=fu;
		res+=w;
		if(++cnt==num-1) return res;
	}
	return res;
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	n=read(),m=read(),k=read();
	bool flg=1;
	for(int i=1;i<=m;i++){
		ee[i].u=read(),ee[i].v=read(),ee[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) flg=0;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	if(flg){
		tot=m;
		num=n+k;
		for(int i=1;i<=m;i++){
			e[i]=ee[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++tot].u=i+n;
				e[tot].v=j;
				e[tot].w=a[i][j];
			}
		}
		cout<<Kruskal()<<endl;
		return 0;
	}
	int ans=1e18;
	for(int x=0;x<(1<<k);x++){
		int res=0ll;
		tot=m,num=n;
		for(int i=1;i<=m;i++){
			e[i]=ee[i];
		}
		for(int i=1;i<=k;i++){
			if((x>>(i-1))&1){
				res+=c[i];
				++num;
				for(int j=1;j<=n;j++){
					e[++tot].u=i+n;
					e[tot].v=j;
					e[tot].w=a[i][j];
				}
			}
		}
		res+=Kruskal();
		//cout<<res<<endl;
		ans=min(ans,res);
	} 
	cout<<ans<<endl;
}

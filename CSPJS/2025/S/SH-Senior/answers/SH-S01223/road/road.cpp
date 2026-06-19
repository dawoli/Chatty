#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+3;
const int maxn=1e4+20;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++) 
ll r(){
	ll x=0;char c;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
} 
int ne[maxm<<1],to[maxm<<1],head[maxn],ct;
ll w[maxm<<1];
int u[maxm<<1],v[maxm<<1];
int fa[maxn];
int fin(int x){
	if(fa[x]!=x){
		fa[x]=fin(fa[x]);
	}
	return fa[x];
}
int n,m,k; 
struct E{
	ll w,u,v;
	bool operator<(const E ok)const{
		return w<ok.w;
	} 
}ed[maxm<<1];
ll w2[maxm];int tot;
void add(int x,int y,ll z){
	ed[++ct]={z,x,y};
}
ll mtr(){
	ll res=0;
	rep(i,1,tot){
		if(fin(ed[i].u)!=fin(ed[i].v)){
			fa[fin(ed[i].u)]=fin(ed[i].v);
			res+=ed[i].w;
		}
	}
	return res;
} ll  ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int uu,vv;ll ww;
	n=r(),m=r(),k=r();
	rep(i,1,n+20)fa[i]=i;
	rep(i,1,m){
		uu=r(),vv=r(),ww=r();
		add(uu,vv,ww);add(vv,uu,ww);
	}
	ll we;
	rep(i,1,k){
		ww=r();
		rep(j,1,n){
			we=r();
			add(n+i,j,we+ww);
			add(j,n+i,we+ww);
		}
	}
	tot=m*2+n*k*2;
	sort(ed+1,ed+1+tot);
	ans=mtr();
	cout<<ans;
	return 0;
}

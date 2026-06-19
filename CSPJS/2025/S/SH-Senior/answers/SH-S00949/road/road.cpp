#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll rd(){
	ll x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&& c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct edge{
	ll u,v,w,vis;
};
ll n,m,k,c[12],is[12],f[10010],ans=1e16;
vector<edge> e;
bool cmp(edge c,edge d){
	return c.w<d.w;
}
ll rt(ll y){
	if(y==f[y]) return f[y];
	return f[y]=rt(f[y]); 
}

int main(){
	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(ll i=1;i<=m;i++){
		edge tmp;
		tmp.u=rd(),tmp.v=rd(),tmp.w=rd(),tmp.vis=0;
		e.push_back(tmp);
	}
	ll z=1;
	for(ll i=1;i<=k;i++){
		c[i]=rd();
		if(c[i]!=0) z=0;
		for(ll j=1;j<=n;j++){
			edge tmp;
			tmp.u=n+i,tmp.v=j,tmp.w=rd(),tmp.vis=i;
			if(tmp.w!=0) z=0;
			e.push_back(tmp);
		}
	} 
	if(z){
		cout<<0;
		return 0;
	}
	sort(e.begin(),e.end(),cmp);
	for(ll x=0;x<(1<<k);x++){
		memset(is,0,sizeof(is));
		ll cnt=0,res=0,cl=0;
		for(ll i=1;i<=n+k;i++) f[i]=i;
		for(ll i=0;i<k;i++) if(x&(1<<i)) is[i+1]=1,res+=c[i+1],cnt++;
		for(ll i=0;cl<n+cnt-1;i++){
			if(e[i].vis!=0 && is[e[i].vis]==0) continue;
			if(rt(e[i].u)==rt(e[i].v)) continue;
			f[rt(e[i].v)]=rt(e[i].u);
			res+=e[i].w;
			cl++;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

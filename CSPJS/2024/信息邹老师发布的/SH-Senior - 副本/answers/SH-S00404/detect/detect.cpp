#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=1e5+5;
long long const inf=0x3f3f3f3f3f3f3f3f;
inline void read(ll &x){
	int res=1,p=0;char c;c=getchar();
	while(c<'0'||c>'9'){if(c=='-')res=-1;c=getchar();}
	while(c>='0'&&c<='9'){p=(p<<3)+(p<<1)+(c-'0');c=getchar();}
	p*=res;
	x=p;
}
struct car{
	ll d,a,v;
	double l,r;
};
car k[maxn];
vector<ll>g[maxn];
ll n,p[maxn],ans,match[maxn],tmp,T,m;
ll len,lim;
bool vis[maxn];
void cal(car &x){
	if(x.a==0){
		if(x.v>lim)x.l=x.d,x.r=len+1;
		else x.l=x.r=len+1;
	}else{
		if(x.v<=lim&&x.a>0)x.l=max(double(x.d),double((lim*lim*1.0-x.v*x.v)/(2*x.a)+x.d)),x.r=len+1;
		else if(x.v>lim&&x.a<0)x.r=min(double(len+1),double((lim*lim*1.0-x.v*x.v)/(2*x.a)+x.d)),x.l=x.d;
		else if(x.v>lim&&x.a>lim)x.l=x.d,x.r=len+1;
		else x.l=x.r=len+1;
	}
	
}
bool tarjan(ll u){
	for(auto i:g[u]){
		if(!match[i]){
			match[i]=u;vis[i]=true;
			return true;
		}else if(tarjan(match[i])&&!vis[i]){
			match[i]=u;vis[i]=true;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	read(T);
	while(T--){
		read(n);read(m);read(len);read(lim);
		for(int i=0;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++){read(k[i].d);read(k[i].v);read(k[i].a);cal(k[i]);}
		for(int i=1;i<=m;i++)read(p[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(k[i].l<p[j]*1.0&&p[j]*1.0<k[i].r){
					if(!vis[i]){ans++;vis[i]=true;}g[i].push_back(j+n);g[j+n].push_back(i);
				}
			}
		}
		cout<<ans<<' ';ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			if(tarjan(i))ans++;
		}
		cout<<ans<<endl;
	}
	
}

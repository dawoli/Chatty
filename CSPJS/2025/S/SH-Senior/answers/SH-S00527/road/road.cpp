#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e4+3,M=1e6+3,K=11;
int n,m,k;
int fa[N+K],v[N+K],Vp=1;
int gfa(int x){
	if(v[x]!=Vp){
		fa[x]=x;
		v[x]=Vp;
		return x;
	}if(fa[x]==x)return x;
	return fa[x]=gfa(fa[x]);
}
#define mg(a,b) fa[gfa(a)]=gfa(b);
#define chk(a,b) (gfa(a)==gfa(b))

pair<int,pair<int,int>> e[M+N*K];
int c[K];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	cin>>n>>m>>k;
	int len=0;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[len++]={w,{u,v}};
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i-n-1];
		for(int j=1;j<=n;j++){
			int q;cin>>q;
			e[len++]={q,{i,j}};
		}
	}
	sort(e,e+len);
	ll res=0x3f3f3f3f3f3full;
	int fms=(1<<k);
	if(k>=9)fms=1;//oops
	for(int ms=0;ms<fms;ms++){
		ll ans=0;
		for(int i=0;i<k;i++)if(!(ms&(1<<i)))ans+=c[i];
		Vp++;
		for(auto& p:e){
			int u=p.second.first,v=p.second.second,w=p.first;
			int kv=u-n-1;if(kv>=0&&((1<<kv)&ms))continue;
			if(chk(u,v))continue;
			mg(u,v);
			ans+=w;
		}
		res=min(res,ans);
	}
	
	cout<<res<<endl;
	
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


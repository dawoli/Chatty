#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read(){
	TN rst=0;bool mns=0;
	char ch=getchar();
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')mns=1,ch=getchar();
	while(isdigit(ch))rst=rst*10+(ch^48),ch=getchar();
	return mns?-rst:rst;
}
int TestCase=1;
inline void main_init();
inline void main_solve();
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//TestCase=read<int>();
	main_init();
	do main_solve();while(--TestCase);
}
inline void main_init(){

}
int n,m,nE,k,fa[10015],a[15];
long long ans;
struct edge{
	int u,v,w;
}e[1000005],E[110005];
inline bool operator<(const edge u,const edge v){
	return u.w<v.w;
}
inline int find(int u){
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
inline void solve(){
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;++i){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		E[++nE]={e[i].u,e[i].v,e[i].w};
		fa[u]=v;
		ans+=e[i].w;
	}
}
inline long long solve(int O){
	for(int i=1;i<=n+k;++i)fa[i]=i;
	long long rst=0;
	for(int o=0;o<k;++o)if((O>>o)&1)rst+=a[o];
	for(int i=1;i<=nE;++i){
		if(E[i].u>n&&!((O>>(E[i].u-n-1))&1))continue;
		int u=find(E[i].u),v=find(E[i].v);
		if(u==v)continue;
		fa[u]=v,rst+=E[i].w;
	}
	return rst;
}
inline void main_solve(){
	n=read<int>(),m=read<int>(),k=read<int>();
	for(int i=1;i<=m;++i){
		e[i].u=read<int>();
		e[i].v=read<int>();
		e[i].w=read<int>();
	}
	solve();
	for(int i=0;i<k;++i){
		a[i]=read<int>();
		for(int j=1;j<=n;++j)
			E[++nE]={n+i+1,j,read<int>()}; 
	}
	sort(E+1,E+nE+1);
	for(int O=1;O<(1<<k);++O)ans=min(ans,solve(O));
	cout<<ans;
}


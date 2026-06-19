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
inline int read(char *a){
	char ch=getchar();
	while(!islower(ch))ch=getchar();
	int len=0;
	while(islower(ch))a[++len]=ch,ch=getchar();
	return len;
}
int TestCase=1;
inline void main_init();
inline void main_solve();
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//TestCase=read<int>();
	main_init();
	do main_solve();while(--TestCase);
}
inline void main_init(){

}
namespace bit{
	int n,tr[15000005];
	inline void init(int N){
		n=N;
		fill(tr+1,tr+n+1,0);
	}
	inline void add(int u,int A){
		while(u<=n)tr[u]+=A,u+=u&(-u);
	}
	inline void add(int l,int r,int A){
		add(l,A),add(r,-A);
	}
	inline int query(int u){
		int rst=0;
		while(u)rst+=tr[u],u&=u-1;
		return rst;
	}
}
int n,m,k,ans[200005];
char a[2][5000005];
namespace trie{
	int nT=1,nD,tr[15000005][26],dfn[15000005],sz[15000005];
	inline int to(int u,char c){
		if(tr[u][c])return tr[u][c];
		return tr[u][c]=++nT;
	}
	namespace edge0{
		int nE,hd[15000005],to[200005],nxt[200005],id[200005];
		inline void dddg(int u,int v,int w){
			to[++nE]=v,nxt[nE]=hd[u],id[nE]=w,hd[u]=nE;
		}
	}
	namespace edge1{
		int nE,hd[15000005],to[200005],nxt[200005];
		inline void dddg(int u,int v){
			to[++nE]=v,nxt[nE]=hd[u],hd[u]=nE;
		}
	}
	namespace midtrie{
		int rt[2][200005];
		inline long long eH(long long u,int v){
			return (u<<30)|v;
		}
		inline array<int,2> dH(long long u){
			return {u>>30,u&1073741823};
		}
		unordered_map<long long,long long> mp;
		inline array<int,2> getrt(int u){
			long long H=eH(rt[0][u],rt[1][u]);
			if(!mp.count(H)){
				int u=++nT,v=++nT;
				mp[H]=eH(u,v);
				return {u,v};
			}
			return dH(mp[H]);
		}
	}
	inline void init(int u){
		sz[u]=1;
		dfn[u]=++nD;
		for(int i=0;i<26;++i)
			if(tr[u][i]){
				init(tr[u][i]);
				sz[u]+=sz[tr[u][i]];
			}
	}
	inline void dfs(int u){
		for(int i=edge1::hd[u];i;i=edge1::nxt[i])
			bit::add(dfn[edge1::to[i]],dfn[edge1::to[i]]+sz[edge1::to[i]],1);
		for(int i=edge0::hd[u];i;i=edge0::nxt[i])
			ans[edge0::id[i]]=bit::query(dfn[edge0::to[i]]);
		for(int i=0;i<26;++i)if(tr[u][i])dfs(tr[u][i]);
		for(int i=edge1::hd[u];i;i=edge1::nxt[i])
			bit::add(dfn[edge1::to[i]],dfn[edge1::to[i]]+sz[edge1::to[i]],-1);
	}
	inline void solve(int u,int v){
		nD=0;
		init(v);
		bit::init(nD);
		dfs(u);
	}
}
inline void main_solve(){
	n=read<int>();
	m=read<int>();
	for(int i=1;i<=n;++i){
		int k=read(a[0]);
		read(a[1]);
		int l=1,r=k;
		while(l<=k&&a[0][l]==a[1][l])++l;
		while(r&&a[0][r]==a[1][r])--r;
		if(l>r)continue;
		trie::midtrie::rt[0][i]=trie::midtrie::rt[1][i]=1;
		for(int j=l;j<=r;++j){
			trie::midtrie::rt[0][i]=trie::to(trie::midtrie::rt[0][i],a[0][j]-'a');
			trie::midtrie::rt[1][i]=trie::to(trie::midtrie::rt[1][i],a[1][j]-'a');
		}
		auto nw=trie::midtrie::getrt(i);
		for(int j=l-1;j;--j)nw[0]=trie::to(nw[0],a[0][j]-'a');
		for(int j=r+1;j<=k;++j)nw[1]=trie::to(nw[1],a[1][j]-'a');
		trie::edge1::dddg(nw[0],nw[1]);
	}
	for(int i=1;i<=m;++i){
		int k=read(a[0]);
		if(read(a[1])!=k)continue;
		int l=1,r=k;
		while(l<=k&&a[0][l]==a[1][l])++l;
		while(r&&a[0][r]==a[1][r])--r;
		int u=1,v=1;
		for(int j=l;j<=r;++j){
			u=trie::tr[u][a[0][j]-'a'];
			v=trie::tr[v][a[1][j]-'a'];
		}
		if(!u||!v)continue;
		long long H=trie::midtrie::eH(u,v);
		if(!trie::midtrie::mp.count(H))continue;
		auto nw=trie::midtrie::dH(trie::midtrie::mp[H]);
		for(int j=l-1;j;--j)nw[0]=trie::to(nw[0],a[0][j]-'a');
		for(int j=r+1;j<=k;++j)nw[1]=trie::to(nw[1],a[1][j]-'a');
		if(!nw[0]||!nw[1])continue;
		trie::edge0::dddg(nw[0],nw[1],i);
	}
	for(auto &u:trie::midtrie::mp){
		auto nw=trie::midtrie::dH(u.second);
		trie::solve(nw[0],nw[1]);
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<'\n';
}


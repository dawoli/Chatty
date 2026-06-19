#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10059;
const ll M=1000009;//最后要测试一下能不能到(1<<9)
const ll K=12;
ll n,m,k,id[N],cnt[1<<K],ans,Bcnt[1<<K],sum,c[K],zgw[1<<K];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
struct edge{
	ll u,v,w;
}es2[M],MST[(1<<10)+2][N],ew[K][N];
bool cmp(const edge&a,const edge&b){return a.w<b.w;}
ll find(ll x){return id[x]==x?x:id[x]=find(id[x]);}
void unite(ll x,ll y){
	ll a=find(x),b=find(y);
	id[a]=b;
}
inline ll LSB(ll x){return x&(-x);}
void add(edge es,ll S){
	ll u=es.u,v=es.v,w=es.w;
	if(find(u)==find(v)) return;
	unite(u,v);
	sum+=w;
//	cout<<u<<" "<<v<<" "<<w<<"\n";
	MST[S][++cnt[S]]=es;
}
void calc(ll preS,ll nowS,ll u){//u号乡村
	ll Ecnt=n+Bcnt[nowS]-1;//应当有这么多条边
//	cout<<"calc:"<<preS<<" "<<nowS<<" "<<Ecnt<<"\n";
	sum=0;//统计当前最小生成树的大小
	for(register ll i=0;i<k;++i)
		if(nowS&(1<<i)) sum+=c[i];
	for(register ll i=1;i<=n+k;++i) id[i]=i;
	for(register ll i=1,j=1;MST[preS][i].u;++i){
		while(j<=n&&ew[u][j].w<=MST[preS][i].w)
			add(ew[u][j],nowS),++j;
		add(MST[preS][i],nowS);
		if(cnt[nowS]==Ecnt) break;
	}//注意在ew[u]里不加n 在外面加n
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=n;++i) id[i]=i;
	for(ll i=1;i<=m;++i)
		es2[i].u=read(),es2[i].v=read(),es2[i].w=read();
	for(ll i=0;i<k;++i){
		c[i]=read();
		for(ll j=1;j<=n;++j){
			ll w=read();
			ew[i][j]=(edge){n+i+1,j,w};
		}
		sort(ew[i]+1,ew[i]+n+1,cmp);
	}//a是连边的费用 c是使用这个城市的费用
	
	sort(es2+1,es2+m+1,cmp);
	//Kruskal
	for(register ll i=1;i<=m;++i){
		ll u=es2[i].u,v=es2[i].v;
		if(find(u)==find(v)) continue;
		MST[0][++cnt[0]]=es2[i];
		ans+=es2[i].w;
		unite(u,v);
		if(cnt[0]==n-1) break;
	}
//	cout<<ans<<"\n";
	//统计Bit信息
	for(register ll S=1;S<(1<<k);++S){
		if(LSB(S)==S) zgw[S]=S;
		else zgw[S]=zgw[S^LSB(S)];
		Bcnt[S]=Bcnt[S^LSB(S)]+1;
	}
	for(register ll S=1;S<(1<<k);++S){
		ll i=0;
		while(1){
			if((1<<i)==zgw[S]) break;
			++i;
		}
		calc(S^zgw[S],S,i);
	}
	cout<<ans;
	return 0;
}

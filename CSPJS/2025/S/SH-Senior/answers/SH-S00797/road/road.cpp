#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll M=1e6+9;
const ll N=10009;
const ll K=19;
ll n,m,k,nE,c[K],fa[N+K];
struct edge{ll u,v,w;} e[M],a[K][N],tmp[M+N*K],t[M+N*K];
bool operator<(edge a,edge b){return a.w<b.w;}
ll Find(ll u){return (fa[u]==u?u:(fa[u]=Find(fa[u])));}
ll Kruskal(){
	ll lp=1,rp=m+1,v=0;
	while(lp<=m&&rp<=nE){
		if(tmp[lp]<tmp[rp]) t[++v]=tmp[lp++];
		else t[++v]=tmp[rp++];
	}
	while(lp<=m) t[++v]=tmp[lp++];
	while(rp<=nE) t[++v]=tmp[rp++];
	for(ll i=1;i<=n+k;i++) fa[i]=i;
	ll res=0;
	for(ll i=1;i<=nE;i++)
		if(Find(t[i].u)!=Find(t[i].v)){
			res+=t[i].w;
			fa[Find(t[i].u)]=Find(t[i].v);
		}
	return res;
}
void solve(){
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)
			cin>>a[i][j].w,a[i][j].u=n+i,a[i][j].v=j;
	}
	ll ans=1e18;
	for(ll i=(*max_element(c+1,c+k+1)?0:(1ll<<k)-1);i<(1ll<<k);i++){
		ll x=0;
		nE=m;
		for(ll j=1;j<=m;j++) tmp[j]=e[j];
		for(ll j=1;j<=k;j++)
			if(i&(1ll<<(j-1))){
				x+=c[j];
				for(ll u=1;u<=n;u++)
					tmp[++nE]=a[j][u];
			}
		sort(tmp+m+1,tmp+nE+1);
		ans=min(ans,Kruskal()+x);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
春江潮水连海平，海上明月共潮生
滟滟随波千万里，何处春江无月明
江流宛转绕芳甸，月照花林皆似霰
空里流霜不觉飞，汀上白沙看不见
江天一色无纤尘，皎皎空中孤月轮
江畔何人初见月，江月何年初照人
人生代代无穷已，江月年年只相似
不知江月待何人，但见长江送流水
白云一片去悠悠，青枫浦上不胜愁
谁家今夜扁舟子，何处相思明月楼
可怜楼上月徘徊，应照离人妆镜台
玉户帘中卷不去，捣衣砧上拂还来
此时相望不相闻，愿逐月华流照君
鸿雁长飞光不度，鱼龙潜跃水成文
昨夜闲潭梦落花，可怜春半不还家
江水留春去欲尽，江谭落月复西斜
斜月沉沉藏海雾，碣石潇湘无限路
不知乘月几人归，落月摇情满江树 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
const ll M=2000009;
inline ll read(){
	register ll x(0),f(1);
	register char c(getchar());
	while(c<'9'||c>'9'){if(c=='-'){f=-1,c=getchar();}}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^'0'); c=getchar();}
	return x*f;
}
struct Edge{
	ll frm,to,w;
}e[M];
bool cmp(const Edge&a,const Edge&b){
	return a.w<b.w;
}
ll nE,n,m,k,p[N];
void add(ll u,ll v,ll w){
	e[++nE]=(Edge){u,v,w};
}
ll root(ll u){
	return p[u]==u?p[u]:p[u]=root(p[u]);
}
void solve0(){
	sort(e+1,e+1+nE,cmp);
	ll ans=0,cnt=0;
	for(ll i=1;i<=nE;i++){
		ll u=e[i].frm,v=e[i].to;
		if(root(u)!=root(v)){
			ans+=e[i].w,cnt++,p[u]=p[v];
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<endl;
}
ll a[12][N],vis[N],ans1=1e13;
void dfs(ll pre){
	if(pre==k){
		for(ll i=1;i<=n+k;i++) p[i]=i;
		ll ans=0,cnt=0,tmp=n;
		for(ll i=1;i<=k;i++){
			if(vis[i]) tmp++,ans+=a[i][0];
		}
		for(ll i=1;i<=nE;i++){
			ll u=e[i].frm,v=e[i].to;
			if(u>n&&!vis[u-n]) continue;
			if(v>n&&!vis[v-n]) continue;
			if(root(u)!=root(v)){
				p[u]=p[v];
				ans+=e[i].w,cnt++;
			}
			if(cnt==tmp-1) break;
		}
		ans1=min(ans,ans1);
		return;
	}
	for(ll i=pre+1;i<=k;i++){
		vis[i]=1;
		dfs(i);
		vis[i]=0;
		dfs(i);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;//或许有些遗憾吧，没有达到预期
	//但是还是很高兴，至少，我尝试过
	//就像题目名一样，路漫漫其修远兮，吾将上下而求索 
	//求得了什么，无处追寻 
	//T1用了2h才写出来，T2不会，T3不会，T4都没看
	//我常常追忆过去 OI带给了我很多
	//我认识了很多新朋友，也有了社交的圈子 
	//这大概就是命运吧，我终究不是OI的料
	//都说女生不适合学这个，我想 我就是一个很好的例子
	//本来还想去noip的，看来也没希望了 
	//afo快乐 后会无期 
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(ll i=1;i<=n+k;i++) p[i]=i;
	if(k==0) solve0();
	for(ll i=1;i<=k;i++){
		cin>>a[i][0];
		for(ll j=1;j<=n;j++) cin>>a[i][j],add(j,i+n,a[i][j]);
	}
	sort(e+1,e+1+nE,cmp);
	dfs(0);
	cout<<ans1<<endl;
	return 0;
}


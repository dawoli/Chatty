#include<bits/stdc++.h>
using namespace std;
//define int long long
typedef long long ll;
#define fr(asd,fgh,i) for(int i=asd,i##end=fgh;i<=i##end;++i)
#define rf(asd,fgh,i) for(int i=asd,i##end=fgh;i>=i##end;--i)
#define maxn 2000007
#define maxm 2000007
int n,m,k;
struct p{
	int u,to,w;
}edge[maxm];
bool cmp(p x,p y){
	return x.w<y.w;
}
int bcj[maxn];
int find(int u){
	if(bcj[u]==u) return u;
	return bcj[u]=find(bcj[u]);
}
vector<pair<int,int> >vc[maxn];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	fr(1,n,i) bcj[i]=i;
	fr(1,m,i){
		cin>>edge[i].u>>edge[i].to>>edge[i].w;
	}sort(edge+1,edge+m+1,cmp);
	int ct=0;
	ll alltog=0;
	fr(1,m,i){
		int u=find(edge[i].u),to=find(edge[i].to);
		if(u==to) continue;
		bcj[u]=to;ct++;
		vc[u].push_back({to,edge[i].w});
		vc[to].push_back({u,edge[i].w});
		alltog+=edge[i].w;
		if(ct==n-1) break;
	}
	printf("%lld\n",alltog);
	return 0;
} 

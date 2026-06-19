#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,c,cost[10010],vis[200010],y[200010],ans=0;
map<pair<int,int>,int> mp;
map<pair<int,int>,int>::iterator it;
struct node{
	int u,v,w;
};
vector<node> edge;
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[200010];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin >> a >> b >> c;
		if(a>b)swap(a,b);
		if(mp[{a,b}]>=c||mp[{a,b}]==0)mp[{a,b}]=c;
	}
	for(int i=1;i<=k;i++){
		cin >> cost[i];
		for(int j=1;j<=n;j++){
			cin >> y[j];
			for(int p=1;p<j;p++){
				if(mp[{p,j}]>=y[p]+y[j]+cost[i]||mp[{p,j}]==0)mp[{p,j}]=y[p]+y[j]+cost[i];
			}
		}
	}
	for(it=mp.begin();it!=mp.end();it++){
		edge.push_back({(*it).first.first,(*it).first.second,(*it).second});
	}
	sort(edge.begin(),edge.end(),cmp);
	for(int i=0;i<edge.size();i++){
		if(find(edge[i].u)!=find(edge[i].v)){
			merge(edge[i].u,edge[i].v);
			ans+=edge[i].w;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

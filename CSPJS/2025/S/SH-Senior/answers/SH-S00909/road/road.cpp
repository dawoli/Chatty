#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,cnt,ans;
int fa[10086],c[15],idx;
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
struct edge{
	int u,v,w;
}ed[1500086];

int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}

void merge(int x,int y){
	int fx = find(x),fy = find(y);
	fa[fx] = fy;
}

bool cmp(edge x,edge y){
	return x.w<y.w;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <=n; ++i)fa[i] = i;
	for(int i = 1; i <=m; ++i){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
		//q.push({ed[idx].w,idx});
	}
	for(int i = 1; i <=k; ++i){
		cin>>c[i];
		for(int j = 1; j <=n; ++j){
			cin>>ed[++idx].u>>ed[idx].v>>ed[idx].w;
			//q.push({ed[idx].w,idx});
		}
	}
	sort(ed+1,ed+m+1,cmp); 
	if(k==0){
		int i = 0;
		while(i<=m){
			i++;
			cout<<ed[i].w<<endl;
			int u = ed[i].u,v = ed[i].v, w = ed[i].w;
			if(find(u)!= find(v)){
				ans+=w,cnt++;
				cout<<w<<" *";
				merge(u,v);
			}
			if(cnt==n-1)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


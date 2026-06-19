#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans,d[10005];
bool vis[10005];
struct Point{
	int v,val;
	bool operator<(const Point& r)const{
		return val<r.val;
	}
	bool operator>(const Point& r)const{
		return val>r.val;
	}
};
vector<Point> G[10004];

priority_queue<Point,vector<Point>,greater<Point> >que;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=2;i<=n;i++)d[i]=(1ll<<32)-1;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	int tmp=G[1].size();
	for(int i=0;i<tmp;i++){
		d[G[1][i].v]=G[1][i].val;
		que.push({G[1][i].v,G[1][i].val});
	}
	vis[1]=true;
	tmp=1;
	while(!que.empty()&&tmp<n){
		int prev=que.top().v;
		if(vis[prev]){
			que.pop();
			continue;
		}
		ans+=que.top().val;
		que.pop();
		vis[prev]=true;
		tmp++;
		int ttmp=G[prev].size();
		for(int i=0;i<ttmp;i++){
			if(!vis[G[prev][i].v]&&G[prev][i].val<d[G[prev][i].v]){
				d[G[prev][i].v]=G[prev][i].val;
				que.push({G[prev][i].v,G[prev][i].val});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


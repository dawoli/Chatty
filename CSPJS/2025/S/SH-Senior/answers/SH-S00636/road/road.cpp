#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;

const int maxn = 1e4 + 15;
struct node{
	ll u,dis,t_id;
	bool operator>(const node o) const{
		return dis > o.dis;
	}
};
struct edge{
	ll to,val;
};
priority_queue<node,vector<node>,greater<node> > q;
vector<edge> mp[maxn];
ll n,m,k,tmp1[maxn][15],tmp2[15][maxn],can[15];
bool vis[maxn];
void input(){
	cin >> n >> m >> k;
	while(m--){
		ll x,y,z;
		cin >> x >> y >> z;
		mp[x].push_back({y,z});
		mp[y].push_back({x,z});
	}
	for(ll t = 1;t <= k;t++){
		cin >> can[t];
		for(ll i = 1;i <= n;i++){
			cin >> tmp1[i][t];
			tmp2[t][i] = tmp1[i][t];
		}
	}
}
void prim(){
	ll sum = 0,cnt = 0;
	q.push({1,0,0});
	while(!q.empty()){
		ll r = q.top().u,d = q.top().dis,id = q.top().t_id;
		q.pop();
		if(vis[r]) continue;
		if(can[id] == 0 && id != 0) d -= can[id]; 
		can[id] = 0;
		cnt++;
		vis[r] = 1;
		sum += d;
		if(cnt == n) break;
		for(auto next : mp[r]){
			if(!vis[next.to]) q.push({next.to,next.val,0});
		}
		for(int t = 1;t <= k;t++){
			for(int to = 1;to <= n;to++){
				if(!vis[to]){
					q.push({to,tmp1[r][t] + tmp2[t][to] + can[t],t});
				}
			}
		}
	}
	cout << sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	prim();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

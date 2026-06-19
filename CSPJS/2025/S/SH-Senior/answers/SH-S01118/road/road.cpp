#include<bits/stdc++.h>
using namespace std;
int n, m, k, basicAns, ans = 0x3f3f3f3f;
//struct road{
//	int v, w;
//};
struct cont{
	int c, a[10005];
}con[15];
//vector<road> road[10005];
int road[10005][10005], vis[10005], dist[10005], troad[10005][10005], in[10005];
int vis2[10005];
struct que{
	int u, v, val;
	bool operator < (const que &x) const{
		return val < x.val;
	}
};
vector<int> vec[10005];
bool check(){
	memset(vis2, 0, sizeof(vis2));
	queue<int> q;
	q.push(1);
	int total = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		vis2[t] =1;
		total++;
		for(int tar : vec[t]){
			if(!vis2[tar]){
				vis2[tar] = 1;
				q.push(tar); 
			}
		}
	}
	return total == n;
}
int findvec(int u, int v){
	int idx = 0;
	for(int tmp : vec[u]){
		if(tmp == v) return idx;
		idx++;
	}
}
void bfs(int basee){
	int j = 0;
	memcpy(troad, road, sizeof(troad));
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	basicAns = 0;
	while(basee){
		j++;
		if(basee & 1){ //振兴第j个乡村 
			basicAns += con[j].c;
			for(int i = 1;i <= n;i++){
				in[i] = n-1;
				for(int kk = 1;kk < i;kk++){
					troad[kk][i] = min(road[kk][i], con[j].a[kk]+con[j].a[i]);
					troad[i][kk] = troad[kk][i];
//					cout<<i<<" "<<kk<<" "<<troad[i][kk]<<endl;
				}
			}
		}
		basee >>= 1;
	}
	priority_queue<que> pq;
	for(int i = 1;i <= n;i++){
		for(j = 1;j < i;j++){
			if(troad[i][j] >= 0x3f3f3f3f-2) continue;
			pq.push({j, i, troad[i][j]});
			basicAns += troad[i][j];
			vec[j].push_back(i);
			if(j != 1){
				pq.push({i, j, troad[i][j]});
				basicAns += troad[i][j];
				vec[i].push_back(j);
			}
		}
	}
	while(!pq.empty()){
		que t = pq.top();
		pq.pop();
		int u = t.u, v = t.v, val= t.val;
//		cout<<u<<" "<<v<<" "<<val<<": "<<in[v]<<endl;
		if(in[v]-1 <= 0) continue;
		vec[u][findvec(u, v)] = vec[u][vec[u].size()-1];
		vec[u].pop_back();
		bool ck = check();
//		cout<<u<<" "<<v<<" "<<val<<": "<<ck<<endl;
		if(!ck){
			vec[u].push_back(v);
		}else{
			basicAns -= val;
			in[v]--;
		}
	}
	ans = min(ans, basicAns);
}
//vector<road> ad[10005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(road, 0x3f3f3f3f, sizeof(road));
	scanf("%d%d%d", &n, &m, &k); 
	for(int i = 1, u, v, w;i <= n;i++){
		scanf("%d%d%d", &u, &v, &w);
		if(u != 1) in[u]++; if(v != 1) in[v]++;
		road[u][v] = w;
		road[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		scanf("%d", &con[i].c);
		for(int j = 1;j <= n;j++){
			scanf("%d", &con[i].a[j]);
		} 
	}
	for(int i = 0;i < 1<<k;i++){
		bfs(i);
	}
	printf("%d", ans); 
	return 0;
}


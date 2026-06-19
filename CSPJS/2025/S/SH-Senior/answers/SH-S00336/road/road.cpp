#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;

int n,m,k;
struct node{
	int to,val;
};
vector<node> l[10000010];
bool flag[100010];
/*
int cnt,sum,ans = 0x14ffffffffffffff;
void dfs(int k){
	if(cnt == n){
		ans = min(sum,ans);
		return;
	}
	for(int i = 0;i<l[k].size();i++){
		if(!flag[l[k][i].to]){
			flag[l[k][i].to] = true;
			sum+=l[k][i].val;
			cnt++;
			cout << cnt  << ' ' << k << ' ' << sum << endl;
			dfs(l[k][i].to);
			cnt--;
			sum-=l[k][i].val;
			flag[l[k][i].to] = false;
		}
	}
}*/
//int ff[1010][1010];
int cnt,sum,ans = 0x14ffffffffffffff;
priority_queue<int> pq;
void bfs(int k){
	cnt++;
	pq.push(k);
	flag[k] = true;
	while(!pq.empty()){
		if(cnt == n){
			ans = min(sum,ans);
		}
		int t = pq.top();
		pq.pop();
		for(int i = 0;i<l[t].size();i++){
			if(!flag[l[t][i].to]){
				cnt++;
				sum+=l[t][i].val;
				//cout << cnt  << ' ' << t << ' ' << sum << endl;
				pq.push(l[t][i].to);
				flag[l[t][i].to] = true;
			}
		}
	}
}
int c[20][100010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		l[u].push_back(node{v,w});
		l[v].push_back(node{u,w});
		//ff[u][v] = w;
		//ff[v][u] = w;
	}	
	for(int i = 1;i<=k;i++){
		cin >> c[i][0];
		bool is_z = false;
		int z_idx=  0;
		for(int j = 1;j<=n;j++){
			cin >> c[i][j];
			if(c[i][j] == 0){
				is_z = true;
				z_idx = j;
			}
		}
		/*if(is_z){
			for(int o = 1;o<=n;o++){
				if(o == z_idx) continue;
				if(ff[z_idx][o] == 0){
					l[z_idx].push_back(node{o,c[i][z_idx]});
				}else{
					
				}
				
			}
				
		}*/
	}
	/*
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<l[i].size();j++){
			cout << i << ' ' << l[i][j].to << ' ' << l[i][j].val << endl;
		}
	}*/
	//cnt++;
	//flag[1] = true;
	//dfs(1);
	bfs(1);
	cout << ans;
	return 0;
}

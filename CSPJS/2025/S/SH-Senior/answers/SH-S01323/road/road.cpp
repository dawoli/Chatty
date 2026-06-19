#include <bits/stdc++.h>
#define int long long 
using namespace std;
array<int,3> edge[2000000];
int fa[20000], sz[20000];
int find(int x){return (fa[x] == x ? x : fa[x] = find(fa[x]));}
void merge(int x,int y){
	x = find(x); y = find(y);
	if(sz[x] > sz[y]) swap(x, y);
	fa[x] = y;
	sz[y] += sz[x];
}
int n,m,k;
vector<array<int,3> > tr;
int sum;
vector<array<int,3> > a[20];
int c[20];
void dfs(int pos,int ch){
	if(pos > k)return;
	dfs(pos+1, ch);
	vector<array<int,3> > tmp, tmd = tr;
	int i,j;
	for(i=0,j=0;i<tr.size() && j<a[pos].size();){
		if(tr[i][0] < a[pos][j][0]){
			tmp.push_back(tr[i]);i ++;
		}
		else{
			tmp.push_back(a[pos][j]); j++;
		}
	}
	while(i < tr.size()) tmp.push_back(tr[i]), i++;
	while(j<a[pos].size()) tmp.push_back(a[pos][j]), j++;
	for(int i=1;i<=n+k;i++) fa[i] = i, sz[i] = 1;
	tr.clear();
	int ans = ch + c[pos];
	for(int i=0;i<tmp.size();i++){
		int x = find(tmp[i][1]), y = find(tmp[i][2]);
		if(x != y){
			merge(x, y); ans += tmp[i][0];
			tr.push_back(tmp[i]);
		}
	}
	sum = min(sum, ans);
	dfs(pos+1, ch + c[pos]);
	tr = tmd;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i][1] >>edge[i][2] >> edge[i][0];
	}
	sort(edge+1, edge+m+1);
	for(int i=1;i<=n+k;i++) sz[i] = 1, fa[i] = i;
	for(int i=1;i<=m;i++){
		int x = find(edge[i][1]), y = find(edge[i][2]);
		if(x != y){
			merge(x, y);
			tr.push_back(edge[i]); sum += edge[i][0];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			a[i].push_back({x, j, n+i});
		}
		sort(a[i].begin(), a[i].end());
	}
	dfs(1, 0);
	cout << sum << endl;
	return 0;
}

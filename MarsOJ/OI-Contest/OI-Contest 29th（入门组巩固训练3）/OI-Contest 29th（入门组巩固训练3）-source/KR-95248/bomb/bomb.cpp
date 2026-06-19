#include <bits/stdc++.h>
using namespace std;

int n, m;
int t, xm[4] = {0, 0, 1, -1}, ym[4] = {1, -1, 0, 0}, vis[1010][1010];
string graph[1010];

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first != b.first){
		return a.first<b.first;
	}
	return a.second < b.second; 
}
pair<int, int> DFS(int x, int y, int f, int r){
	if(x >= n || x<0 || y>=m||y<0||vis[x][y]||graph[x][y] == '*'){
		return {1e9, 1e9};
	}
	//cout << x << " "<<y<<" "<<f<<" "<<r<<endl;
	vis[x][y] = 1;
	if(x == n-1 && y == m-1){
		return {f, r};
	}

	pair<int, int> min_;
	min_.first = 1e9;
	min_.second = 1e9;
	for(int i = 0;i<4;i++){
		pair<int,int> tmp = DFS(x+xm[i], y+ym[i], f+(graph[x][y] == '$'), r+1);
		if(cmp(tmp, min_)){
			min_ = tmp;
		}
	}
	return min_;
}
int main(){
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	cin >> t;
	while(t--){
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for(int i = 0;i<n;i++){
			cin >> graph[i]; 
		}
		pair<int, int> tmp = DFS(0, 0, 0, 0);
		cout << tmp.first << " " << tmp.second << endl;
	}
} 

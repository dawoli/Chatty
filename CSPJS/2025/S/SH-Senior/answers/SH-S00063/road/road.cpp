#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e6 + 1e4;
int n, m, k;
struct edge{
	int u;
	int v;
	int w;
};
int f[N];
int co[100];
int vis[100];
bool cmp(edge a, edge b){
	return a.w < b.w;
}
void init(){
	for(int i=1; i<N; i++) f[i] = i;
}
int root(int num){
	if(f[num] == num) return num;
	else return f[num] = root(f[num]);
}
void unite(int x, int y){
	int rootx = root(x);
	int rooty = root(y);
	if(rootx != rooty) f[rootx] = y;
}
bool together(int x, int y){
	if(root(x) == root(y)) return true;
	else return false;
}
bool all(){
	int root1 = root(1);
	for(int i=2; i<=n; i++){
		if(root(i) != root1) return false;
	}
	return true;
}
//edge heap[N] = {};
//int idx;
//void insert(edge n){
//	heap[++idx] = n;
//	int son = idx;
//	int fa = idx / 2;
//	while(heap[fa].w > heap[son].w){
//		swap(heap[fa], heap[son]);
//		son = fa;
//		fa /= 2;
//		if(fa == 0) break;
//	}
//}
//void pop(){
//	heap[1] = heap[idx--];
//	int fa = 1;
//	int son;
//	if(heap[fa*2+1].w > heap[fa*2].w) son = fa * 2;
//	else son = fa * 2 + 1;
//	if(son == fa * 2 + 1 && son > idx) son--;
//	if(son > idx) return ;
//	while(heap[son].w < heap[fa].w){
//		swap(heap[son], heap[fa]);
//		fa = son;
//		son = fa * 2;
//		if(heap[fa*2+1].w > heap[fa*2].w) son = fa * 2;
//		else son = fa * 2 + 1;
//		if(son == fa * 2 + 1 && son > idx) son--;
//		if(son > idx) return ;
//	}
//}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	//freopen("r.in", "w", stdin);
	vector<edge> s;
	cin >> n >> m >> k;
	int count = m + (k * n);
	init();
	for(int i=1; i<=m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		//insert({u, v, w});
		s.push_back({u, v, w});
	}
	for(int i=1; i<=k; i++){
		int cost;
		cin >> cost;
		co[i] = cost;
		for(int j=1; j<=n; j++){
			int c;
			cin >> c;
			//insert({i+n, j, c});
			s.push_back({i+n, j, c+cost});
		}
	}
	sort(s.begin(), s.end(), cmp);
	long long sum_cost = 0;
	int cnt = 0;
	//int tong[11][100001] = {};
	for(int i=0; i<count; i++)/*while(idx)*/{
		edge r = s[i];
		//edge r = heap[1];
		//pop();
		int u = r.u;
		int v = r.v;
		int w = r.w;
		//if(u > n && !vis[u-n]){
		//	vis[u-n] = 1;
		//	w += co[u-n];
//			insert({u, v, w});
//			tong[u-n][v] = 1;
//			continue;
		//}
//		else if(u > n && vis[u-n] && tong[u-n][v] == 1){
//			tong[u-n][v] = 0;
//			w -= co[u-n];
//		}
		if(!together(u, v)){
			unite(u, v);
			sum_cost += w;
			cnt++;
			if(all()) break;
		}
	}
	cout << sum_cost << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

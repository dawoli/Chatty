#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
	bool operator < (const edge & other)const{
		return w < other.w;
	}
}edges[1100014];
struct village{
	int c;
	edge a[10014];
}villages[12];
int n,m,k,minimum = 1000000000000000000,ans,root[10014];
int Find(int i){
	if(root[i] == i)return i;
	return Find(root[i] = root[root[i]]);
} 
void Union(int i,int j){
	root[Find(i)] = Find(j);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0 ; i < m; i++){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].u--;
		edges[i].v--;
	}
	sort(edges, edges + m);
	for(int i = 0; i < k; i++){
		cin >> villages[i].c;
		for(int j = 0; j < n; j++){
			cin >> villages[i].a[j].w;
			villages[i].a[j].u = n + i;
			villages[i].a[j].v = j;
		}
	}
	for(int i = 0; i < (1 << k); i++){
		for(int i = 0; i < n + k; i++){
			root[i] = i;
		}
		vector<edge> v;
		ans = 0;
		for(int j = 0; j < k; j++){
			if(i & (1 << j)){
				ans += villages[j].c;
				for(int x = 0; x < n; x++){
					v.push_back(villages[j].a[x]);
				}
			}
		}
		sort(v.begin(),v.end());
		int ptr1 = 0,ptr2 = 0,used = 0;
		while(used < n + __builtin_popcount(i) - 1){
			if(ptr2 == v.size()){
				if(Find(edges[ptr1].u) != Find(edges[ptr1].v)){
					Union(edges[ptr1].u, edges[ptr1].v);
						ans += edges[ptr1].w;
					used++;
				}
				ptr1++;
		 	}
			else{
				if(edges[ptr1].w > v[ptr2].w){
					if(Find(v[ptr2].u) != Find(v[ptr2].v)){
						Union(v[ptr2].u, v[ptr2].v);
						ans += v[ptr2].w;
						used++;
					}
					ptr2++;
				}
				else{
					if(Find(edges[ptr1].u) != Find(edges[ptr1].v)){
						Union(edges[ptr1].u, edges[ptr1].v);
						ans += edges[ptr1].w;
						used++;
					}
					ptr1++;
				}
			}
		}
		minimum = min(minimum,ans);
	}
	cout << minimum;
	return 0;
}  

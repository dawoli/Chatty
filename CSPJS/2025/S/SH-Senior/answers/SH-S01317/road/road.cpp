#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
int n , m , k ,id[N] ,ans;
int root(int i){
	return id[i] == i? i : id[i] = root(id[i]);
}
struct edge{
	int u , v , c;
}e[N];
bool cmp(const edge &a,const edge &b){
	return a.c < b.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);                     
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int u  , v , c;
		cin >>u >> v >> c;
		e[i] = edge{u,v,c};
	}
	for (int i = 1;i <= k;i++){
		int ijk ;
		cin >> ijk;
		for (int iijjkk = 1;iijjkk <= n ;iijjkk++){
			cin >> ijk;
//			to[n+i].push_back(j);
//			w[n+i].push_back(k);
//			to[j].push_back(n+i);
//			w[j].push_back(k);
		}
	}
	for (int i =0;i <= n ;i++){
		id[i] = i;
	}
	sort(e+1,e+m+1,cmp);
	for (int i =1 ; i <= m ;i++){
		if (root(e[i].u) == root(e[i].v)){
			continue;
		}
		ans += e[i].c ;
//		cout << e[i].u <<" " <<e[i].v << endl;
		id[root(e[i].u)] = root(e[i].v);
	} 
	cout << ans;
	return 0;
}

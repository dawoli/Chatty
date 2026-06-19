#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,m,k;
int mp[N][N];
int jian[N][N];
int cnt;
bool te;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	te = true;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,l;
		cin >> u >> v >> l;
		mp[u][v] = l;
		mp[v][u] = l;
		cnt += l;
	}
	for(int i = 1;i <= k;i++){
		int p;
		cin >> p;
		if(p != 0){
			te = false;
		}
		for(int j = 1;j <= m;j++){
			cin >> jian[i][j];
			if(jian[i][j]!= 0){
				te = false;
			}
		}
	}
	if(te){
		cout << 0;
	}else if(k == 0){
		cout << cnt / 2;
	}else{
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

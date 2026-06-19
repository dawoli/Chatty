#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,x,y,c[200010],a[200010],l[200010],ok[110][2010];
vector<int> to[200010],w[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int o = 1;o <= t;o++){
		cin >> n >> m >> q;
		for(int i = 1;i <= 200000;i++) c[i] = 0;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			cin >> l[i];
			for(int j = 1;j <= l[i];j++){
				cin >> a[j];
				if(!c[a[j]]) c[a[j]] = ++cnt;
				for(int k = max(1,j - m + 1);k < j;k++){
					to[c[a[k]]].push_back(c[a[j]]);
					w[c[a[k]]].push_back(i);
				}
			}
		}
		for(int i = 0;i <= 100;i++){
			for(int j = 1;j <= cnt;j++) ok[i][j] = -1;
		}
		ok[0][c[1]] = 0;
		for(int i = 0;i <= 9;i++){
			for(int j = 1;j <= cnt;j++){
				if(ok[i][j] == -1) continue;
				for(int k = 0;k < to[j].size();k++){
					if(w[j][k] == ok[i][j]) continue;
					ok[i + 1][to[j][k]] = (ok[i + 1][to[j][k]] == -1 || ok[i + 1][to[j][k]] == w[j][k]?w[j][k]:0);
				}
			}
		}
		for(int i = 1;i <= q;i++){
			cin >> x >> y;
			cout << (c[y] && ok[x][c[y]] != -1) << endl;
		}
		for(int i = 1;i <= cnt;i++){
			while(to[i].size()){
				to[i].pop_back();
				w[i].pop_back();
			}
		}
	}
	return 0;
}

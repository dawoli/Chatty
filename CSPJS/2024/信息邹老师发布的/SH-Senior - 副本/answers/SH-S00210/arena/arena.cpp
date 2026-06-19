#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],t,x[4],al[510];char c[510][510];
vector<int> f[510][510];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> al[i];
	for(int i = 1;i <= m;i++) cin >> b[i];
	int op = log(n) / log(2) + 1;
	for(int j = 1;j <= n;j *= 2){
		if(n == j) op--;
	}
	for(int i = 1;i <= op;i++){
		for(int j = 1;j <= (1 << (op - i));j++) cin >> c[i][j];
	}
	for(int i = 1;i <= (1 << op);i++) f[0][i].push_back(i);
	cin >> t;
	for(int o = 1;o <= t;o++){
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for(int i = 1;i <= n;i++) a[i] = al[i] ^ x[i % 4];
		int ans = 0;
		for(int i = 1;i <= m;i++){
			op = log(b[i]) / log(2) + 1;
			for(int j = 1;j <= b[i];j *= 2){
				if(b[i] == j) op--;
			}
			for(int j = 1;j <= op;j++){
				for(int k = 1;k <= (1 << (op - j));k++){
					while(f[j][k].size()) f[j][k].pop_back();
					if(c[j][k] == '0'){
						bool ok = 0;
						for(int o = 0;o < f[j - 1][k * 2 - 1].size();o++){
							if(a[f[j - 1][k * 2 - 1][o]] >= j && f[j - 1][k * 2 - 1][o] <= b[i]) f[j][k].push_back(f[j - 1][k * 2 - 1][o]);
							else{
								ok = 1;
								if(f[j - 1][k * 2 - 1][o] > b[i]) f[j][k].push_back(f[j - 1][k * 2 - 1][o]);
							}
						}
						if(ok){
							for(int o = 0;o < f[j - 1][k * 2].size();o++) f[j][k].push_back(f[j - 1][k * 2][o]);
						}
					}
					else{
						bool ok = 0;
						for(int o = 0;o < f[j - 1][k * 2].size();o++){
							if(a[f[j - 1][k * 2][o]] >= j && f[j - 1][k * 2][o] <= b[i]) f[j][k].push_back(f[j - 1][k * 2][o]);
							else{
								ok = 1;
								if(f[j - 1][k * 2][o] > b[i]) f[j][k].push_back(f[j - 1][k * 2][o]);
							}
						}
						if(ok){
							for(int o = 0;o < f[j - 1][k * 2 - 1].size();o++) f[j][k].push_back(f[j - 1][k * 2 - 1][o]);
						}
					}
				}
			}
			int cnt = 0;
			for(int j = 0;j < f[op][1].size();j++) cnt += f[op][1][j];
			ans ^= (cnt * i);
		}
		cout << ans << endl;
	}
	return 0;
} 

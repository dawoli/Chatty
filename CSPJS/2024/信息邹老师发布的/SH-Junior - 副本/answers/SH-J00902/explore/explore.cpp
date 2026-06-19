#include<bits/stdc++.h>
using namespace std;
int t;
int n[1000],m[1000],k[1000000];
int x[30],y[30],d[30];
string c[105][105];
int ans = 1;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n[t] >> m[t] >> k[t];
		cin >> x[t] >> y[t] >> d[t];
		for(int i = 1;i <= n[t];i++){
			for(int j = 1;j <= m[t];j++){
				cin >> c[n[t]][m[t]];
				cout << c[n[t]][m[t]];
			}
		}
		for(int i = 1;i <= k[t];i++){
			if(d[t] == 0){
				y[t] += 1;
				if(x[t] <= 0 && x[t] > n[t] && y[t] <= 0 && y[t] > m[t] || c[x[t]][y[t]] == 'x'){
					y[t] -= 1;
					d[t] = (d[t] + 1) % 4;
				} else {
					ans++;
				}
			}
			if(d[t] == 1){
				x[t] += 1;
				if(x[t] <= 0 && x[t] > n[t] && y[t] <= 0 && y[t] > m[t] || c[x[t]][y[t]] == 'x'){
					x[t] -= 1;
					d[t] = (d[t] + 1) % 4;
				} else {
					ans++;
				}
			}
			if(d[t] == 2){
				y[t] -= 1;
				if(x[t] <= 0 && x[t] > n[t] && y[t] <= 0 && y[t] > m[t] || c[x[t]][y[t]] == 'x'){
					y[t] += 1;
					d[t] = (d[t] + 1) % 4;
				} else {
					ans++;
				}
			}
			if(d[t] == 3){
				x[t] -= 1;
				if(x[t] <= 0 && x[t] > n[t] && y[t] <= 0 && y[t] > m[t] || c[x[t]][y[t]] == 'x'){
					x[t] += 1;
					d[t] = (d[t] + 1) % 4;
				} else {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

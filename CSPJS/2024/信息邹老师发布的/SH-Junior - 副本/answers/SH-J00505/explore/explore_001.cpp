#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char c[1001][1001];
bool f[10001] = {false};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		long long res = 1;
		long long n,m,k;
		cin >> n >> m >> k;
		long long x,y,d;
		cin >> x >> y >> d;
		for(long long i = 1; i <= m; i++){
			for(long long j = 1; j <= n; j++){
				cin >> c[i][j];
			}
		}
		d--;
		if(k == 1){
			x += dx[d];
			y += dy[d];
			if(0 < x && x <= n && 0 < y && y <= m){
				cout << 2<< endl;
				continue;
			}else{
				cout << 1 << endl;
				continue;
			}
		}else{
			f[x] = true;
			while(k > 0){
				if(d == 2){
					d = 3;
					k--;
				}else if(d == 0){
					d = 1;
					k--;
				}
				if(k <= 0){
					cout << 1 << endl;
				}else{
					if(d == 3){
						if(x > 0){
							k--;
							x = x - 1;
							f[x] = true;
						}else{
							k -= 2;
							d = 1;
						}
					}else{
						if(x < m){
							k--;
							x += 1;
							f[x] = true;
						}else{
							k -= 2;
							d = 3;
						}
					}
				}
			}
			
			/*
			while(k > 0){
				bool flag = false;
				for(int i = d; i <= d + 3 && !flag; i++){
					k--;
					i = i % 4;
					//cout << "i = " << i << endl;
					int xc = x + dx[i];
					//cout << "xc = " << xc << endl;
					if(0 < xc && xc <= m){
						if(c[1][xc] == false){
							flag = true;
							x = xc;
							res++;
							c[1][xc] = true;
						}
					}
				}
				//cout << k<< endl;
			}
			cout << res;
			*/
		}
		for(int i = 1; i <= m; i++){
			if(f[i]){
				res++;
			}
		}
		cout << res << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

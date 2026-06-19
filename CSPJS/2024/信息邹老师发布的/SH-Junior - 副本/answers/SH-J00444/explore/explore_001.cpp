#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
long long n,m,k;
bool v[1005][1005];
bool check(int x,int y){
	return (x < 1 or x > n or y < 1 or y > m or c[x][y] == 'x');
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t;
	cin >> t;
	while(t--){
		long long x,y,d;
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> c[i][j];
			}
		}
		long long ans = 0;
		while(k--){
			if(!v[x][y]){
				ans++;
				v[x][y] = true;
			}
		    int nx,ny;
		    if(d == 0){
		    	nx = x;
		    	ny = y+1;
			}
			else if(d == 1){
				nx = x+1;
				ny = y;
			}
			else if(d == 2){
				nx = x;
				ny = y-1;
			}
			else{
				nx = x-1;
				ny = y;
			}
			if(check(nx,ny)){
				d += 1;
				d %= 4;
			}
			else{
				x = nx;
				y = ny;
			}
		} 
		if(!v[x][y]){
			ans++;
			v[x][y] = true;
		}
		for(int i = 0;i < 1005;i++){
			for(int j = 0;j < 1005;j++){
				v[i][j] = false;
			}
		}
		cout << ans << "\n";
	}
} 

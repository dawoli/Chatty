#include<iostream>
using namespace std;

int a[1005][1005];
bool f[1005][1005] ={{false}};
int t,n,m,k,y,x,d;

bool check(int x,int y){
	return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 0;
}

void clear(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j] = false;
		}
	}
}

void solve(){
	int nx,ny;
	for(int i=0;i<k;i++){
		f[x][y] = true;
		switch(d){
			case 0:
				nx = x;
				ny = y+1;
				break;
			case 1:
				nx = x+1;
				ny = y;
				break;
			case 2:
				nx = x;
				ny = y-1;
				break;
			case 3:
				nx = x-1;
				ny = y;
				break;
		}
		if(check(nx,ny)){
			x = nx;
			y = ny;
		}else{
			d = (d+1)%4;
		}
		f[x][y] = true;
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j] == true){
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		clear();
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int j=1;j<=n;j++){
			string dd;
			cin >> dd;
			for(int cc=1;cc<=5;cc++){
				if(dd[cc-1] == 'x')a[j][cc] = 1;
				else a[j][cc] = 0;
			}
		}
		solve();
	}
	return 0;
}

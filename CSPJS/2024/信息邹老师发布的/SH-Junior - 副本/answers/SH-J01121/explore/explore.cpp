#include <bits/stdc++.h>
using namespace std;
int T = 0,n=0,m=0,x=0,y=0,d=0,xx=0,yy=0,k=0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for(int i = 0;i < T;i++){
		int ans=1;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		char a[1010][1010];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0;i < k;i++){
			if(x + dx[d] > 0 && x + dx[d] <= n && y + dy[d] > 0 && y + dy[d] <= m && a[x+dx[d]][y+dy[d]] == '.'){
				x += dx[d];
				y += dy[d];
				ans++;
			}else{
				d = (d + 1) % 4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*1
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....*/ 

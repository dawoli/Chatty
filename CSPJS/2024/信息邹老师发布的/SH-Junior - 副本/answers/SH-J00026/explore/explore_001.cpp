#include <bits/stdc++.h>
using namespace std;
pair<int,int> next_step(int x,int y,int d){
	if(d == 0) return {x,y + 1};
	else if(d == 1) return {x + 1,y};
	else if(d == 2) return {x,y - 1};
	else if(d == 3) return {x - 1,y};
}
char mp[1005][1005];
bool walk[1005][1005]; 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int q;
	cin >> q;
	while(q --){
		int x,y,d,n,m,k;
		cin >> n >> m >> k >> x >> y >> d;
		x --;
		y --;
		memset(walk,0,sizeof(walk));
		walk[x][y] = 1;
		for(int i = 0;i < n;i ++) for(int j = 0;j < m;j ++) cin >> mp[i][j];
		while(k --){
			pair<int,int> next = next_step(x,y,d);
			int nx = next.first;
		    int ny = next.second;
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == '.'){
				x = nx;
				y = ny;
				walk[x][y] = 1;
			}
			else{
				d = (d + 1) % 4;
			}
		}
		int ans = 0;
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < m;j ++){
				ans += walk[i][j]; 
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
 ..xx.
x....
*/

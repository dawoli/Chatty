#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,t;
char map1[1003][1003];
int row[4] = {0,1,0,-1},col[4] = {1,0,-1,0};
bool vis[1003][1003];
void clear(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			vis[i][j] = 0;
		}
	}
}
int zou(int r,int c,int d){
	vis[r][c] = 1;
	int num = 1;
	for(int i = 1;i <= k;i++){
		int rr = r + row[d];
		int cc = c + col[d];
		if(rr >= 1 && rr <= n && cc >= 1 && cc <= m && map1[rr][cc] == '.'){
			r = rr;
			c = cc;
			if(vis[r][c] == 0){
				num++;
				vis[r][c] = 1; 
			}
		}else{
			d = (d + 1) % 4;
		}
	}
	return num;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		clear();
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> map1[i][j];
			}
		}
		cout << zou(x,y,d) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool p[1005][1005];
bool book[1005][1005];
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool isok(int x, int y){
	if(x>n||x<1||y>m||y<1||p[x][y])return false;
	return true;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		memset(p, 0, sizeof p);
		memset(book, 0, sizeof book);
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char k;
				cin >> k;
				if(k=='x')p[i][j] = 1;
			}
		}
		book[x][y] = 1;
		while(k--){
			
			if(isok(x+dx[d], y+dy[d])){
				x += dx[d], y+=dy[d];
			}else d = (d+1)%4;
			book[x][y] = 1;
		}
		int res = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(book[i][j])res++;
			}
		}
		cout << res << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

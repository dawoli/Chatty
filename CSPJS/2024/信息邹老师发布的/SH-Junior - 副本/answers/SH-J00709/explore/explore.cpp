#include<iostream>
using namespace std;
inline long long read(){
	register char c = getchar();
	register int x = 0 , f = 1;
	for ( ; c < '0' || c > '9' ; c = getchar()){
		if (c == '-'){
			f = -1;
		}
	}
	for ( ; c >= '0' && c <= '9' ; c = getchar()){
		x = x * 10 + c - 48;
	}
	return f * x;
}
inline void write(long long x){
	if (x >= 10){
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
int t , dx[4] = {0 , 1 , 0 , -1} , dy[4] = {1 , 0 , -1 , 0};
int main(){
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	t = read();
	while (t--){
		long long n , m , k , x , y , d , ans = 1;
		char a[1001][1001] = {};
		bool vis[1001][1001] = {};
		n = read();
		m = read();
		k = read();
		x = read() - 1;
		y = read() - 1;
		d = read();
		for (register int i = 0 ; i < n ; i++){
			for (register int j = 0 ; j < m ; j++){
				a[i][j] = getchar();
			}
			getchar();
		}
		vis[x][y] = 1;
		while (k--){
			int nx = x + dx[d] , ny = y + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '.'){
				x = nx;
				y = ny;
				ans += !vis[nx][ny];
				vis[nx][ny] = 1;
			}else{
				d = (d + 1) % 4;
			}
		}
		write(ans);
		putchar(10);
	}
	return 0;
}

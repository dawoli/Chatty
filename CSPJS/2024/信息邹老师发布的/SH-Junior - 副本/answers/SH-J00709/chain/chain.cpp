#include<iostream>
using namespace std;
inline int read(){
	char c = getchar();
	int x = 0 , f = 1;
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
inline void write(int x){
	if (x >= 10){
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
int t;
int main(){
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out" , "w" , stdout);
	t = read();
	while (t--){
		int n , k , q , a[100001][200001] , l;
		bool cnt[200001] = {};
		n = read();
		k = read();
		q = read();	
		for (int i = 0 ; i < n ; i++){
			l = read();
			for (int j = 0 ; j < n ; j++){
				a[i][j] = read();
				cnt[a[i][j]] = 1;
			}
		}
		while (q--){
			int r , c;
			r = read();
			c = read();
			if (!cnt[c]){
				putchar(48);
				putchar(10);
				continue;
			}
			putchar(49);
			putchar(10);
		}
	}
	return 0;
}

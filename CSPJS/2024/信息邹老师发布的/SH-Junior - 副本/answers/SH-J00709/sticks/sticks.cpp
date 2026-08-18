#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
inline int read(){
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
inline void write(int x){
	if (x < 0){
		putchar(45);
		x = -x;
	}
	if (x >= 10){
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
// inline int ceil(double x){
// 	return int(x) == x ? int(x) : int(x) + 1;
// }
struct node{
	int step , s , v;
}t;
long long T , n = 11;
int a[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int cnt[8] = {-1 , -1 , 1 , 7 , 4 , 2 , 6 , 8};
int main(){
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	T = read();
	while (T--){
		n = read();
		if (n < 8){
			write(cnt[n]);
			putchar(10);
			continue;
		}
		queue <node> q;
		for (register int i = 1 ; i <= 9 ; i++){
			q.push({1 , a[i] , i});
		}
		while (q.size()){
			t = q.front();
			q.pop();
			if (t.step == ceil(n / 7.0) && t.s == n){
				write(t.v);
				putchar(10);
				break;
			}
			for (register int i = 0 ; i <= 9 ; i++){
				q.push({t.step + 1 , t.s + a[i] , t.v * 10 + i});
			}
		}
	}
	return 0;
}

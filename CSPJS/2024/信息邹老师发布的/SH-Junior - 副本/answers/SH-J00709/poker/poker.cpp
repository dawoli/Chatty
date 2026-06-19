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
int n;
int main(){
	freopen("poker.in" , "r" , stdin);
	freopen("poker.out" , "w" , stdout);
	n = read();
	write(52 - n);
	return 0;
}

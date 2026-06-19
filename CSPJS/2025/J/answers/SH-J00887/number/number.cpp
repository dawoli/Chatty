#include <cstdio>
#include <iostream>
using namespace std;

int l[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 0; i < 10; i++){
		l[i] = 0;
	}
	char c;
	while(cin >> c){
		if(c >= '0' && c <= '9'){
			l[c - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int o = 1; o <= l[i]; o++){
			printf("%c", i + '0');
		}
	}
	return 0;
} 

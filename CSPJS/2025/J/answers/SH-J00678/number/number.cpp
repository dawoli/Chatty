#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a;
	int list[256] = {};
	while(cin >> a){
		list[int(a)] += 1;	
	} 
	for(int i = '9'; i >= '0'; i--){
		for(int j = 0; j < list[i]; j++){
			cout << char(i);
		} 
	}
	return 0;
} 

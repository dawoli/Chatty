#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, b, c, n;
	cin >> n;
	if(n != 3){
		cout << "I don't know";
		return 0;
	}
	cin >> a >> b >> c;
	if(a+b > c and b+c > a and a+c > b){
		cout << "1";
	} else{
		cout << "0";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	if(a + b > c and abs(a - b) < c){
		if(a + c > b and abs(a - c) < b){
			if(b + c > a and abs(b - c) < a){
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}

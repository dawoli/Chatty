#include<bits/stdc++.h>
using namespace std;
int n;
int k, a[500005], sum = 0;
int x[500005];
bool flag = true;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int c = 0; c < n; c++){
		int l = 0;
		for(int j = c; j < n; j++){
			l = a[j] ^ l;
			if(l == k){
				x[c] = j - c + 1;
				break;
			}
		}
	}
	for(int c = 0; c < n; ){
		flag = true;
		if(x[c] == 0){
			c++; continue;
		}
		for(int j = c; j < c + x[c]; j++){
			if(x[j] != 0 && j + x[j] < c + x[c]){
				c = j; flag = false; break;
			}
		}
		if(flag){
			sum++; c = c + x[c];
		}
	}
	cout << sum;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n,k;
int a[N];

bool check(int mid){
	int sum = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] == k){
			sum++;
		}
	}
	int x;
	for (int i = 1; i <= n; i++){
		if (a[i] != k){
			x = a[i];
			for (int j = i + 1; j <= n; j++){
				if (a[j] == k){
					i = j + 1;
					break;
				}
				x ^= a[j];
				if (x == k){
					i = j + 1;
					sum++;
					break;
				}
			}
		}
	}
	if (sum >= mid){
		return true;
	}
	return false;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int l = 0,r = n;
	while (l < r){
		int m = (l+r+1)/2;
		if (check(m)){
			l = m;
		}
		else{
			r = m - 1;
		}
	}
	cout << l;
	return 0;
}

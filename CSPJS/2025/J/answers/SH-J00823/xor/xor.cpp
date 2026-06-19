#include<bits/stdc++.h>
using namespace std;
int a[500000 + 50];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int cnt = 0, pre = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre = pre ^ a[i];
		if(a[i] == k || pre == k){
			cnt++;
			pre = 0;
		}
	}
	cout << cnt;
	return 0;
}

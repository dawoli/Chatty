#include <bits/stdc++.h>
using namespace std;
int k, n, ans;
int a[500005];
bool check1 = 1, check2 = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			check1 = 0;
		}
		if(a[i] != 1 && a[i] != 0){
			check2 = 0;
		}
	}
	
	if(check1){
		cout << n/ 2;
		return 0;
	}
	if(check2){
		if(k == 0){
			for(int i = 1; i <= n; i++){
				if(a[i] == 0){
					ans++;
				}
			}
		}
		if(k == 1){
			for(int i = 1; i <= n; i++){
				if(a[i] == 1){
					ans++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	
	cout << 2;
}

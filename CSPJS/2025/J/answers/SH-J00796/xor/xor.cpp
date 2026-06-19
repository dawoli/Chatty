#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, k, ans, a[N];

int main (){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	int f = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != 1){
			f = 0;
		}
	}
	
	if (k == 0 && f){
		cout << n/2;
	}
	
	else if (k <= 1){
		if (k == 1){
			for (int i = 1; i <= n; i++){
				if (a[i] == 1){
					ans++;
					a[i] = 1e9;
				}
			}
		}else{
			for (int i = 1; i <= n; i++){
				if (a[i] == 0){
					ans++;
					a[i] = 1e9;
				}
			}
			
			for (int i = 2; i <= n; i++){
				if (a[i] == a[i-1] && a[i] != 1e9 && a[i-1] != 1e9){
					a[i] = 1e9;
					a[i-1] = 1e9;
					ans++;
					i++;
				}
			}
		}
		
		cout << ans;
	}

	return 0;
}

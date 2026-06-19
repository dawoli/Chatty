#include <bits/stdc++.h>
using namespace std;

int n, k, arr[500005];
bool f = true, f1 = true;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		cin >> arr[i];
		if (arr[i] != 1) f = false;
		if (arr[i] > 1) f1 = false;
	}
	if (n <= 2 && f) cout << 1;
	else if (f) cout << n / 2;
	else if (f1){
		if (k == 1){
			int cnt = 0, cnt2 = 0;
			for (int i = 1; i <= n; i ++){
				if (arr[i] == 1)  cnt ++;
			}
			for (int i = 1; i <= n - 1; i ++){
				if (arr[i] + arr[i + 1] == 1)  cnt2 ++;
			}
			cout << max(cnt, cnt2);
		}else{
			int cnt = 0, cnt2 = 0;
			for (int i = 1; i <= n; i ++){
				if (arr[i] == 0)  cnt ++;
			}
			for (int i = 1; i <= n - 1; i ++){
				if (arr[i] + arr[i + 1] == 2)  cnt2 ++;
			}
			cout << max(cnt, cnt2);			
		}
	}
	return 0;
}

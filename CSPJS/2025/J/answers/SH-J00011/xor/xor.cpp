#include <bits/stdc++.h>
using namespace std;
int li[500010];
int pre[500010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> li[i];
	}
	pre[1] = li[1];
	for (int i = 2; i <= n; i++){
		pre[i] = pre[i - 1] ^ li[i];
	}
	int cnt = 0;
	int rrr = -1;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int num;
			if (i == 1){
				num = pre[i];
			}
			num = pre[j] ^ pre[i-1]; // i到j的前缀异或
			if (num == k && i > rrr){
				cnt++;
				rrr = j;
				break;
			}
		} 
	}
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

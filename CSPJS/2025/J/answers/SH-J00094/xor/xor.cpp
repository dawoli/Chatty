#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long a[MAXN];
long long sum[MAXN];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	long long lastone = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = (sum[i - 1] ^ a[i]);
		if(a[i] == k){
			ans++;
			sum[i] = 0;
			lastone = i + 1;
		}else{
			if(sum[i] == k){
				ans++;
				sum[i] = 0;
				lastone = i + 1;
			}else{
				for(long long j = i - 1; j >= lastone; j--){
					if((sum[i] ^ sum[j]) == k){
						ans++;
						sum[i] = 0;
						lastone = i + 1;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

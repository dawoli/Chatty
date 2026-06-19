#include<bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n, t, a[100010][5], cnt[5], ls[100010], cs[100010], idx, k, ans;
//priority_queue<long long> pq;
void solve(){
	ans = 0;
	for(int i = 1; i <= 3; i++){
		cnt[i] = 0;
	}
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
		long long x = a[i][1], y = a[i][2], z = a[i][3];
		if(x >= y && x >= z){
			cs[i] = 1;
			ans += x;
			cnt[1]++;
		}
		else if(y >= x && y >= z){
			cs[i] = 2;
			ans += y;
			cnt[2]++;
		}
		else if(z >= x && z >= y){
			cs[i] = 3;
			ans += z;
			cnt[3]++;
		}
	}

	k = 0;
	for(int i = 1; i <= 3; i++){
//		printf("%lld\n", cnt[i]); 
		if(cnt[i] > n / 2){
			k = i;
		}
	}
	if(k == 0){
		printf("%lld\n", ans);
	}
	else{
		idx = 0;
		for(int i = 1; i <= n; i++){
			if(cs[i] != k){
				continue;
			} 
			idx++;
			ls[idx] = inf;
			for(int j = 1; j <= 3; j++){
				if(j != k){
					ls[idx] = min(ls[idx], a[i][k] - a[i][j]);
				}
			}
//			printf("%lld\n", ls[idx]);
		}
		sort(ls + 1, ls + idx + 1);
		for(int i = 1; i <= cnt[k] - n / 2; i++){
//			printf("ls%lld\n", ls[i]);
			ans -= ls[i];
		}
		printf("%lld\n", ans);
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		solve();
	}
	return 0;
} 

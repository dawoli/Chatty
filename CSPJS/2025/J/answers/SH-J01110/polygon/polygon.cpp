#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long pow_mod(long long a, long b){
	long long res = 1;
	while(b > 0){
		if(b % 2 == 1){
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b/=2;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i =0; i < n; i++){
		cin >> a[i]; 
	} 
	sort(a.begin(),a.end());
	long long total = (pow_mod(2,n)-1+MOD)%MOD;
	long long invalid1 = n % MOD;
	long long invalid2 = (1LL * n * (n-1)/2)%MOD;
	long long invalid3 = 0;
	for(int i = 0 ;i < n ; i++){
		int sum_other = 0;
		for(int j = 0; j < n; ++j){
			if(j!=i){
				sum_other+=a[j];
			}
		}
		int left = 0, right = n - 1;
		int best = -1;
		while(left <= right){
			int mid = (left + right)/2;
			int s = 0;
			for(int j = 0; j <= mid ;j++){
				if(j != i){
					s+=a[j];
				}
					 
			}
			if(s <= a[i]){
				best = mid;
				left = mid + 1;
			}
			else{
				right = mid-1;
			}
		}
		long long cnt = 0;
		if(best != -1){
			cnt = pow_mod(2,best+1) - 1;
			if(i <= best){
				cnt = (cnt - 1 + MOD);
			}
		} 
		invalid3 = (invalid3 + cnt) % MOD;
	}
	long long ans = (total -invalid1 - invalid2 - invalid3 -3 + MOD) % MOD;
	cout << ans << endl;
} 


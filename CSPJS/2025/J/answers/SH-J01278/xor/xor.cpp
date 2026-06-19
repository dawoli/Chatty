#include<bits/stdc++.h>
using namespace std;
long long a[500010] , dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == m) dp[i] = 1;
	}
	for(long long i = 1; i <= n; i++){
		long long x = a[i];
		for(long long j = 0; j <= i; j++){
			for(long long k = 1; k <= j; k++) x = x xor a[i - k];
			if(x == m){
				dp[i] = max(dp[i], dp[i - j - 1] + 1);
			}
		}
	}
	long long maxa = -1;
	for(int i = 1; i <= n; i++){
		maxa = max(dp[i] , maxa);
	}
	cout << maxa << endl;
	return 0;
} 

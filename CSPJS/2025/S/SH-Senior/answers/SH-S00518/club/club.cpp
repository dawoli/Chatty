#include <bits/stdc++.h>
using namespace std;
int tests;
int dp[100000];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &tests);
	for(int test=1;test<=tests;test++){
		int n=0;
		int a[100000], b[100000], c[10000];
		scanf("%d", &n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			dp[i] = dp[i-1] + max(a[i], max(b[i], c[i]));

			
		}
		cout << dp[n] << endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 5e5+10;
int n, k;
int ans;
int a[N], sum[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
	}
	int l = 1, r = 1;
	while(r<=n){
		if((sum[r]^sum[l-1]) == k){
			r++; 
			l = r;
			ans++;
		}else{
			r++;
		}
	}
	cout << ans << endl;
	return 0;
}

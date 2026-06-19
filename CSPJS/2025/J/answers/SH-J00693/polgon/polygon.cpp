#include<bits/stdc++.h>
using namespace std;
long long n, a[5005], pre[5005], res[5005];
long long sum = 0;
const int z = 998244353;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);	
	cin >> n;
	for(long long c = 1; c <= n; c++){
		cin >> a[c];
		pre[c] = pre[c - 1] + a[c];
	}
	sort(a + 1, a + n + 1);
	
	for(long long c = 3; c <= n; c++){
		if(a[c] == a[c - 1]){
			sum = (sum + 1) * 2 - 1;
			continue;
		}
		if(pre[c] <= 2 * a[c]) continue;
		if(c > 3) res[c] = pre[c] - 2 * a[c];
		else res[c] = 1;
		res[c] %= z;
		if(res[c - 1] > 0) res[c] *= res[c - 1]; 
		res[c] /= (c * c);
		res[c] %= z;
		res[c] += res[c - 1];
		sum += res[c];
		sum = sum % z;
	}
	cout << sum;
	return 0;
}

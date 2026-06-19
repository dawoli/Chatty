#include<bits/stdc++.h>
using namespace std;
int x[500005];
int sumx[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,ans=0,k,maxn = 0;
	sumx[0] = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		if(x[i] > maxn) maxn = x[i];
		sumx[i] = sumx[i-1] ^ x[i];
	}
	if(maxn == 1) {
		if(k == 1) cout << n;
		else if(k == 0) cout << n/2;
		return 0;
	}
	int p=1;
	// n<=5e5
	for(int i = 1; i <= n; i++) {
		for(int j = p; j <= i; j++) {
			int s = sumx[i] ^ sumx[j-1];
//			cout << sumx[i] << " " << sumx[j-1] << endl;
//			if(j == 0) s ^= sumx[0];
			if(s == k){
				ans++;
				p=i+1;
				break;
			}
		}
	}
	cout << ans << endl; 
	
	return 0;
}

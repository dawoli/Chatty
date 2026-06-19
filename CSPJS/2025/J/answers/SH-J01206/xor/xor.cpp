#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		a[i] ^= a[i-1]; 
	}
	int ed=n+1;
	for (int i=1;i<=n+1;i++){
		if (i > ed){
			ans++;
			ed = n+1;
		}
		if (i == n+1) break;
		for (int j=i;j<=n;j++){
			if (int(a[i-1]^a[j]) == k){
				ed = min(ed,j);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

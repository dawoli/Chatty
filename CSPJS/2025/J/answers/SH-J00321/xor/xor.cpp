#include<bits/stdc++.h>
using namespace std;
bool v[100007];
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		if(i==k) ans++;
		for(int j = i; j < n; j++){
			if((j xor i) == k) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

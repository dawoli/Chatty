#include <bits/stdc++.h>
using namespace std;
int a[500005],sum,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			sum = a[i];
			for(int k = i;k <= j;k++){
				sum |= a[k];
			}
			if(sum == k) cnt++;
		}
		sum = 0;
	}
	cout << cnt << endl;
	return 0;
}

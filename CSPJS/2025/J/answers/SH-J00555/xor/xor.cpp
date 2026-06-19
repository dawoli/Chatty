#include<bits/stdc++.h>
using namespace std;
int a[500005],sum,ans,b = -1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		sum = a[i];
		if(i <= b){
			continue;
		}
		if(a[i] == k){
			ans++;
			b = max(b,i);
			continue;
		}
		for(int j = i+1;j <= n;j ++){
			sum = (sum^a[j]);
			if(sum == k){
				if(ans == 0) {
					ans++;
					b = max(b,j);
					break;
				}
				else{
					if(j <= b){
						break;
					}
					else{
						ans++;
						b = max(b,j);
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

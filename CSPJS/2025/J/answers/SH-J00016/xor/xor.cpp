#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout << ans;
	
	
	
	return 0;
}

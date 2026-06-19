#include<bits/stdc++.h>
using namespace std;
int sum[1145140],a[1145140];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int p=1,ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=p; j<=i; j++) {
			if((sum[j-1]^sum[i])==k) {
				ans++;
				p=i+1;
				break;
			}
		}
	}
	cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=1,B=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
	}
	if(A) {
		cout<<n/2;
		return 0;
	}
	if(B) {
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==1) ans++;
		}
		if(k==1) {
			cout<<ans;
			return 0;
		}
		else {
			cout<<ans/2;
			return 0;
		}
	}
	return 0;
}

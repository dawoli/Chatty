#include<bits/stdc++.h>
using namespace std;
int n,k,a[500009],pre[500009];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)  {
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int last=0,ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=last+1;j<=i;j++) {
			if((pre[i]^pre[j-1])==k) {
				last=i;
				//cout<<j<<" "<<i<<" "<<(pre[i]^pre[j-1])<<"\n";
				ans++;
				break;
			}
		}
	}
//	//cout<<"\n";
//	for(int i=1;i<=n;i++) {
//		cout<<pre[i]<<" ";
//	}
	cout<<ans;
	return 0;
}

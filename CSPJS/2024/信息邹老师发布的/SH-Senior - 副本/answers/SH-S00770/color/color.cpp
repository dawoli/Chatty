#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],ans;
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(a[i]==a[j] and i!=j) {
					ans+=a[i];
				}
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}

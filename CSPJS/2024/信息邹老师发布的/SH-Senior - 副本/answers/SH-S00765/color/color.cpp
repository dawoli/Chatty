#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[200005];
bool c[200005];
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			for(int j=1;j<i;j++) {
				if(a[j]==a[i]) {
					ans+=a[j];
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

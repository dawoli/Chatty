#include<bits/stdc++.h>
using namespace std;
int n;
int a[200009],c[200009];
void solve() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(n<=100) {
		int ans=0;
		for(int i=0;i<(1<<n);i++) {
			int now=0;
			int k=i;
			for(int j=1;j<=n;j++) {
				c[j]=k%2;
				for(int o=j-1;o>=0;o--) {
					if(c[o]==c[j]) {
						if(a[o]==a[j]) {
							now+=a[j];
							break;
						}
						else break;
					}
				}
				k/=2;
			}
			ans=max(ans,now);
		}
		cout<<ans<<endl;
	}
	else {
		
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	if(a[3]<a[1]+a[2]) {
		ans=1;
	} else {
		ans=0;
	}
	cout<<ans<<"\n";
	return 0;
}

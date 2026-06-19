#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,sum[505];
int sl(int n) {
	
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			sum[j]+=a[i];
		}
	}
	sort (a+1,a+n+1);
	if (n==3) {
		if (a[3]*2 < a[1]+a[2]+a[3]) return 1;
		return 0;
	}
	while (n>=3) {
		if (a[n]*2 <sum[n]) return 1+(n-1)*sl(n-1);
		else return (n-1)*sl(n-1);
	}
}
int main() {
	//freopen ("polygon.in ","r",stdin);
	//freopen ("polygon.out ","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		for (int j=i;j<=n;j++) {
			sum[j]+=a[i];
		}
	}
	sort (a+1,a+n+1);
	if (n==3) {
		if (a[3]*2 < a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
	}
    else if(a[n]==1) {
    	cout<<((n-1)*(n-2))/2;
	}
	else cout<<sl(n);
	return 0;
}

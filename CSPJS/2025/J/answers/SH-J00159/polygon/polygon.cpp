#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
/*	int sum=0,maxm=0,ans=0;
	for(int i=3;i<=n;i++) {
		if(i==3) {
			for(int j=1;j<=n;j++) {
				for(int k=j;k<=n;k++) {
					for(int l=k;l<=n;l++) {
						sum=a[j]+a[k]+a[l];
						maxm=max(a[j],max(a[k],a[l]));
						if(sum>2*maxm) ans++;
					}
				}
			}
		}
	}*/
	cout<<n/2+1;
	return 0;
}

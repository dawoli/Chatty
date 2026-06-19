#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5001];
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	maxa=max(a[i],maxa);
	sort(a, a+n);
	for(i=0; i<n; i++)
	if(a[0]+a[1]+a[2]>a[2]*2){
		cout << 1;
		return 0;
	} else {
		cout << 0;
		return 0;
	}
	if(a[n-1]==1) {
		long long Sum=0;
		for(int j=3; j<=n; j++)
		for(int i=3; i<=n; i++) {
			Sum=(Sum+Sum(n-i+1))%MOD
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ooo(int o,int p) {
	int cont=0;
	for(int i=o; i<=p; i++) {
		cont+=a[i];
	}
	return cont;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0; i<n-2; i++) {
		for(int j=i+2; j<n; j++) {
			int ma=a[j]*2;
			if(ooo(i,j)>ma) {
				ans++;
				cout<<i<<" "<<j;
			}
		}
	}
	for(int i=0; i<n-2; i++) {
		for(int j=i+2; j<n; j++) {
			for(int k=i+1; k<j; k++) {
				int ma=a[j]*2;
				if(ooo(i,j)-a[k]>ma) {
					ans++;
					cout<<i<<" "<<j;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}













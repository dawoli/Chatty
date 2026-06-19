#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans=0;
int n,k;
int out(int c,int b) {
	int coun=0;
	for(int i=c; i<=b; i++) {
		coun=coun^a[i];
	}
	return coun;
}
void ooo(int c,int b) {
	for(int i=c; i<=b; i++) {
		for(int j=i+1; j<=b; j++) {
			if(out(i,j)==k) {
				ans++;
				i=j+1;
			}
		}
	}
	return;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int mi=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k) {
			ans++;
			ooo(mi,i);
			mi=i+1;
		}	
	}ooo(mi,n);
	cout<<ans;
	return 0;
}













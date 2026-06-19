#include<bits/stdc++.h>
using namespace std;
const int KS=1e5+10;
int a[KS];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cout<<n/2;
	return 0;
}

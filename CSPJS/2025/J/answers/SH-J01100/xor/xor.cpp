#include<bits/stdc++.h>
using namespace std;
int n,k,book[500010],a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int c=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		c+=a[i];
	}
	if(c==n) {
		if(k==0) {
			cout<<n/2;
		}
		else {
			cout<<n;
		}
			return 0;
	}
	return 0;
}

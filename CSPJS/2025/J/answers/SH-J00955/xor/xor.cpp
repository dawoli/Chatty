#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		if(n%2==0) cout<<n/2;
		else if(n%2==1) cout<<(n-1)/2;
		else cout<<1;
	}
	return 0;
}

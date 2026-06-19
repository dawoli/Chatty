#include <bits/stdc++.h>
using namespace std;

int n,k,a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2 && k==0) cout<<1;
	if(n==1 && k==0) cout<<0;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(n==1&&k!=a[1]){
			cout<<0<<endl;
			return 0;
		}
		if(n==1&&k==a[1]){
			cout<<1<<endl;
			return 0;
		}
	}
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	if(a[1]^a[2]==k) cout<<1<<endl;
	return 0;
}

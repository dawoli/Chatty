#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int c1,c0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
			c1++;
		if(a[i]==0)
			c0++;
	}
	if(c1==n){
		cout<<n/2;
		return 0;
	}
	if(c1+c0==n){
		if(!k){
			cout<<c1/2+c0;
		}
		else if(k==1){
			cout<<c1;
		}
		return 0;
	}
	return 0;
}

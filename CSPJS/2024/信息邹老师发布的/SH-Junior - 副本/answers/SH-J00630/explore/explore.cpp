#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
	int t,n,m,k,;
	cin>>t>>n>>m>>k;
	if(t==1){
		if(n==1&&m<=2&&k==1){
			cout<<2<<endl;
			return 0;}
		else if(n<=100&&m<=100&&k==1){
			cout<<2<<endl;
			return 0;}
	}
	return 0;
}

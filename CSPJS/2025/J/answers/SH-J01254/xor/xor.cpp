#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t0=0,t1=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)    t0++;
		else if(a[i]==1)    t1++;
	}
	if(k==1){
		cout<<t1;
	}
	else if(k==0){
		if(n<=2)    cout<<"0";
		else(n>1000)    cout<<t0;
		
	}
	return 0;
}

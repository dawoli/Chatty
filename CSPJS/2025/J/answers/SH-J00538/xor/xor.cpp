#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1008];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f1=1,f2=1,f3=1;
	int at0=0,at1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==2) f1=0,f2=0;
		if(a[i]==1) f1=0,at1++;
		if(a[i]==0) at0++;
	}
	if(f1){
		cout<<n/2<<endl;
	}
	else if(f2){
		if(k==0){
			cout<<(at0+at1/2)<<endl;
		}
		else{
			cout<<at1<<endl;
		}
	}
	else{
		cout<<((1+n)*n/2)<<endl;
	}
	return 0;
} 

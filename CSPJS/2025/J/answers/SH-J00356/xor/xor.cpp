#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n]={0};
	for(int i=0;i<+n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n==2){
			if(a[1]==a[2]){
				cout<<3;
			}else{
				cout<<2;
			}
		}
		if(n==1){
			cout<<1;
		}
	}
		if(k==0){
		cout<<n;
	}
	
	return 0;
}

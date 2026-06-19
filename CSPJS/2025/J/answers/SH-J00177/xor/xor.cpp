#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int count=1;
	int l=0,r=0;
	if(n<=2 && k==0){
		if(n==0){
			cout<<"0";
		}
		if(n==1){
			cout<<"0";
		}
		if(n==2){
			cout<<"1";
		}
	}
	return 0;
}

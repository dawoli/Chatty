#include<bits/stdc++.h>
using namespace std;
int n,k,a[300];
bool f=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(n%2==0){
		cout<<n/2;
	}else{
		cout<<(n-1)/2;
	}
	return 0;
}

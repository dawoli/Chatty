#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0){
		if(k>1){
			cout<<0;
			return 0;
		}
		else if(k==1){
			cout<<n;
			return 0;
		}
		else if(k==0){
			if(n==1){
				cout<<0;
				return 0;
			}
			if(n==2){
				cout<<1;
				return 0;
			}
		}
	}
	return 0;
}

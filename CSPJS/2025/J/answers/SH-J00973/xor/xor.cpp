#include<bits/stdc++.h>
using namespace std;
int n,k,ls[500005],a1=1,a01=1;
int sol1(){
	if(k==1){
		int ones=0;
		for (int i=1;i<=n;i++){
			if(ls[i]==1){
				ones++;
			}
		}
		return ones;
	}
	else{
		int zero=0;
		for (int i=1;i<=n;i++){
			if(ls[i]==0){
				zero++;
				continue;
			}
			if(ls[i]==ls[i+1]){
				zero++;
				i++;
			}
		}
		return zero;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>ls[i]; 
		if(ls[i]!=1){
			a1=0;
		}
		if(ls[i]>1){
			a01=0;
		}
	}
	if(a1){
		cout<<n/2;
		return 0;
	}
	if(a01){
		cout<<sol1();
		return 0;
	}
}

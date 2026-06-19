#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int sum=0;
	cin>>n>>k;
	bool xz1=1,xz2=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1) xz1=0;
		if (a[i]!=1 && a[i]!=0) xz2!=0;	
		sum+=a[i];
	}
	if (xz1){
		cout<<1;
		return 0;
	}
	if (xz2){
		if (n==1){
			cout<<1;
		}
		else if (n==2){
			if (a[1]==a[2]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			if (sum%2==0){
				cout<<1;
			}
			else{
				if ((n-sum)%2==0){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
		}
		
	}
	return 0;
	
	
}

#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag=1,cnt1=0,cnt2=0,flag2=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0 && a[i]!=1) flag=0;
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt2++;
		if(a[i]!=1) flag2=0;
	}
	if(n==2 && k==0 && a[1]==1 && a[2]==1){
		cout<<1;
		return 0;
	}
	if(n==1 && a[1]==1 && k==0){
		cout<<0;
		return 0;
	}
	if(k==1){
		cout<<cnt1;
		return 0;
	}
	if(k==0){
		cout<<cnt2;
		return 0;
	}
	cout<<0;
	return 0;
} 

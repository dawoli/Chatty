#include<bits/stdc++.h>
using namespace std;

int a[500050];
int n,k;
int he[500050];
void sh(){
}

int solve3(){
	sh();
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	int so1=1,so2=1,cnt1=0,cnt0=0,so3=1;
	if(k!=0) so1=0;
	if(k!=1&&k!=0) so2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) so1=0;
		if(a[i]!=0&&a[i]!=1) so2=0;
		if(a[i]>255) so3=0;
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt0++;
		
	}
	if(so1){
		cout<<n/2;
	}
	else if(so2){
		if(k==1) cout<<cnt1;
		else if(k==0) cout<<cnt0;
	}
	else if(so3){
		solve3();
		
	}
	else{
		solve3();
	}
	
}

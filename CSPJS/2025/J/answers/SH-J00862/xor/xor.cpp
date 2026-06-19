#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+7;
int a[N],ac[N],n,k;
void cal1(){
	int cnt0=0,cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		if(x==0) cnt0++;
		if(x==1) cnt1++;
		a[i]=x;
	}
	for(int i=1;i<n;i++){
		if(a[i]==1&&a[i+1]==1){
			i+=2;
			cnt2++;
		}
	}
	if(k==0){
		cout<<cnt0+cnt2;
		return;
	}
	else if(k==1){
		cout<<cnt1;
		return;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k<=1){
		cal1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ac[i]=ac[i-1]^a[i];
	}
	int l=1,r=1,x=ac[r]^ac[l-1],ans=0;
	while(l<=r){
		if(x<k) r++;
		else{
			if(x==k) ans++;
			l++;
		}
		x=ac[r]^ac[l-1];
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5005],a1=1;
#define int long long
int sol(){
	int ones=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			ones++;
		}
	}
	int ans=0;
	for(int i=3;i<=ones;i++){
		int temp=1;
		for (int j=ones;j>ones-i;j--){
			temp*=j;
			temp/=ones-j+1;
		}
		ans+=temp;
		ans%=998244353;
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			a1=0;
		}
	}
	if(n<3){
		cout<<0;
	}
	if(n==3){
		int tot=a[1]+a[2]+a[3];
		if(tot>a[1]*2&&tot>a[2]*2&&tot>a[3]*2){
			cout<<1;
		} 
		else{
			cout<<0;
		}
		return 0;
	}
	if(a1){
		cout<<sol();
	}
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod1=998,mod2=244,mod3=353;
int a[5010];
unsigned long long C(int n,int m){
	int sum=1;
	for(int i=n;i>m;i--) sum*=i,sum%=mod1,sum%=mod2,sum%=mod3;
	for(int i=n-m;i>=2;i--) sum/=i;
	return sum; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool flag=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1) flag=false;
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))) cout<<1;
		else cout<<0;
	}else if(flag){
		unsigned long long ans=0;
		for(int i=3;i<=n;i++) ans+=C(n,i),ans%=mod1,ans%=mod2,ans%=mod3;
		cout<<ans; 
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mxn=0,mod=998244353;
int ksm(int a,int n){
	int ret=1;
	while(n){
		if(n%2==1) ret*=a;
		n/=2;
		a*=a;
		a%=mod;
		ret%=mod;
	}
	return ret;
}
bool check(int x,int mx){
	int sum=0,bit=1;
	while(x){
		if(x%2==1) sum+=a[bit];
		bit++;x/=2;
	}
	if(sum>mx) return true;
	else return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i];mxn=max(mxn,a[i]);}
	if(mxn==1){
		int ans=ksm(2,n);
		ans-=1;
		ans-=n;
		ans-=(n*(n-1)/2);
		ans%=mod;
		cout<<ans;
	}
	else if(n<=20){
		int ans=0;
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			int mx=a[i];
			for(int j=1;j<(1<<(i-1));j++){
				if(check(j,mx)) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 

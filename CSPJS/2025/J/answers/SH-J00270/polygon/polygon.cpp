#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000];
long long back(int nu,int ne){
	if(nu==1){
		if(a[1]>ne) return 1;
		else return 0;
	}
	else{
		return (back(nu-1,ne)+back(nu-1,ne-a[nu]))%998244353;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>=21){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		cout<<(ans-n-1-n*(n-1)/2)%998244353;
	}
	else{
		long long ans=0;
		for(int i=2;i<=n;i++){
			ans+=back(i,a[i+1]+1);
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}

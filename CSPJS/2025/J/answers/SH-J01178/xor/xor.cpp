#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[50005],b[50005];
long long f(int l,int r,int length){
	if(l>r||l+length-1>r) return 0;
	long long ma=0;
	int kl=length;
	while(kl<=l+r&&l+kl-1<=r){
		for(int i=l;i+kl-1<=r;i++){
			int j=i+kl-1;
			if((b[j]^b[i-1])==k){
				long long p=f(l,i-1,kl+1)+f(j+1,r,kl)+1;
				ma=max(ma,p);
			}
		}
		kl++;
	}
	return ma;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=(a[i]^b[i-1]); 
	} 
	long long ans=0,_p=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans+=f(_p,i-1,2);
			ans++;
			_p=i+1;
		}
	}
	ans+=f(_p,n,2);
	cout<<ans;
	return 0;
}

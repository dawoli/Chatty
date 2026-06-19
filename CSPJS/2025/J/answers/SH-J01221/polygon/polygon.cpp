#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,ans;
long long a[5001]; 
long long choose[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxlen=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxlen){
			maxlen=a[i];
		} 
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(maxlen==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2%mod;
		}
		ans-=n;
		ans-=n*(n-1)/2;
		ans--;
		cout<<ans;
		return 0;
	}
	
}

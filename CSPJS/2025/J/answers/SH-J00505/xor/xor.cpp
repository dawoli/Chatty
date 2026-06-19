#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[6000000],cnt[6000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,sum=0;
	cin>>n>>k>>a[1];
	cnt[1]=a[1];
	for(ll i=2;i<=n;i++){
		cin>>a[i];
		cnt[i]=cnt[i-1]^=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		if(cnt[j]^cnt[i]==k){
			sum++;
			j+=1;
			i=j;
		}
	}
	}
	cout<<sum; 
	return 0;
}

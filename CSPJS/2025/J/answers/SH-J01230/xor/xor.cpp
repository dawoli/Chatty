#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	bool flag=0;
	ll s,cnt1=0;
	for(s=1;s<=n;s++){
		ll x;
		cin>>x;
		if(x==0){
			flag=1;
		}
		if(x==1){
			cnt1++;
		}
	}
	if(flag){
		if(k==0){
			cout<<cnt1/2;
		}else{
			cout<<cnt1; 
		}
	}else{
		cout<<n;
	}
	return 0;
}  

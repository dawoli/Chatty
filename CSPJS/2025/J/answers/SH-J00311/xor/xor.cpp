#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==1){
		ll cnt=0;
		for(ll i=0;i<n;i++){
			if(a[i]==1) cnt++;
		} 
		cout<<cnt;
	}
	else{
		ll cnt=0;
		for(ll i=0;i<n;i++){
			if(a[i]==0) cnt++;
			else if((a[i]==1)&&(a[i+1]==1)){
				cnt++;
				i++;
			}
		}
		cout<<cnt;
	}
	return 0;
}

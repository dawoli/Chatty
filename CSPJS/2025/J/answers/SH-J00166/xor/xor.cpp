#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500009];
ll s[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	ll j=0,cnt=0,t=0;
	for(int i=1;i<=n;i++){
		for(j=t;j<i;j++){
			if((s[i]^s[j])==k){
				t=i;
				cnt++;
				break;
			} 
		}
	}
	cout<<cnt;
	return 0;
}


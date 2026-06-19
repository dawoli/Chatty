#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	string AFO;
	cin>>AFO;
	ll s,c0=0;
	for(s=1;s<=n;s++){
		ll x;
		cin>>x;
		if(x==0){
			c0++;
		}
	}
	n-=c0;
	ll res=1;
	for(s=1;s<=n;s++){
		res*=s;
		res%=MOD;
	}
	cout<<res;
	return 0;
} 

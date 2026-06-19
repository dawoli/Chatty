#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e2+10;
ll a[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll l=n*m;
	ll s;
	for(s=1;s<=l;s++){
		cin>>a[s];
	}
	ll rec=a[1],reci;
	sort(a+1,a+l+1,cmp);
	for(s=1;s<=l;s++){
		if(a[s]==rec){
			reci=s;
		}
	}
	if(reci%(2*n)==0 || reci%(2*n)>n){
		cout<<reci/(2*n)*2+2<<" ";
		if(reci%(2*n)==0){
			cout<<1;
		}else{
			cout<<2*n+1-reci;
		}
	}else{
		cout<<reci/(2*n)*2+1<<" "<<reci%(2*n);
	}
	return 0;
}  

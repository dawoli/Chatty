#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[100009],cnt[100009],s[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll n;
	cin>>n;
	ll a;
	for(ll i=1;i<=n;i++){
		cin>>a;
		cnt[a]++;
	}
	ll k=1;
	for(ll i=1;i<=100000;i++){
		if(cnt[i]!=0)r[k++]=cnt[i];
	}
	for(ll i=1;i<k;i++){
		s[i]=s[i-1]+r[i];
	}
	ll lazy=0;
	for(ll i=1;i<k;i++){
		if(r[i]>=s[i-1]-lazy)
			lazy=s[i-1];
		else lazy=lazy+r[i];
	}
	cout<<s[k-1]-lazy;
	return 0;
}

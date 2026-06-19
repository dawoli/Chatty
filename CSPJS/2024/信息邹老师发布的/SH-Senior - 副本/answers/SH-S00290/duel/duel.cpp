#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,s[100005],a,maxn=-1,ans=-1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a;
		s[a]++;
		ans=max(ans,s[a]);
		//maxn=max(maxn,a);
	}
/*	for(int i=1;i<=maxn;i++){
		ans=max(ans,s[i]);
	}*/
	cout<<ans;
	return 0;
}

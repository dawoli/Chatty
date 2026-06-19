#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll n,r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>r[i];
	}
	sort(r+1,r+1+n);
	ll cnts=0,cnte=0;
	for(ll i=1;i<=n;++i){
		if(r[i]>r[i-1]){
			cnts+=cnte;
			cnte=0;
		}
		if(cnts>0)cnts--;
		cnte++;
	}
	ll ans=cnts+cnte;
	cout<<ans<<endl;
	return 0;
}

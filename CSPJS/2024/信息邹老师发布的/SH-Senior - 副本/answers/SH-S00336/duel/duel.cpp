#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r[100005],cnt,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		r[k]++;
	}
	for(ll i=1,k;i<=100003;i++){
		k=min(cnt,r[i]);
		cnt=cnt+r[i]-k;
		ans+=k;
	}
	cout<<n-ans;
	return 0;
}
//rp++

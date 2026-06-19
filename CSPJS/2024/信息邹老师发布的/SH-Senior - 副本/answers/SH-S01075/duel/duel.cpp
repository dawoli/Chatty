#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005];
priority_queue<ll,vector<ll>,greater<ll> >q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		ll x=q.top();
		if(a[i]>x)q.pop();
		q.push(a[i]);
	}
	ll ans=0;
	while(!q.empty()){
		ans++;
		q.pop();
	}
	cout<<ans;
	return 0;
} 

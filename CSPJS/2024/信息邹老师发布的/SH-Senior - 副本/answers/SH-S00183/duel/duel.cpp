#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll a[N];
//ll b[N];
//int cnt=0;
priority_queue< ll,vector<ll>,greater<ll> > q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(!q.empty()){
			if(q.top()<a[i]){
			q.pop();
			ans++;
			}
		}
		q.push(a[i]);
	}
	cout<<n-ans;
	return 0;
}

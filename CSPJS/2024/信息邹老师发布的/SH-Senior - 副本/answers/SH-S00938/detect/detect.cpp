#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5;
ll t,d[N+5],v[N+5],p[N+5];
bool isp[N+5];
ll nxt[N+5];
ll solve(){
	ll n,m,l,vl;
	cin>>n>>m>>l>>vl;
	for(ll i=1;i<=n;i++)
		cin>>d[i]>>v[i]>>a[i];
	for(ll i=1;i<=m;i++)	cin>>p[i];
	ll cnt=0;
	for(ll i=1;i<=n;i++)
		if(d[i]<=p[m]&&v[i]>vl)	cnt++;
	cout<<cnt<<" ";
	if(cnt==0)	return m;
	return m-1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++)
		cout<<solve()<<endl;
	return 0;
} 

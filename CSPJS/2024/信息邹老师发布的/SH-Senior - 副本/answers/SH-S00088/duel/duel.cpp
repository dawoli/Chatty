#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100009
ll n,r[N],f[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+1+n);
	for(ll i=1;i<=n;i++){
		if(r[i]==r[i-1])f[i]=f[i-1];
		else f[i]=i-1;
		if(ans<f[i])ans++;
	}
	cout<<n-ans;
	return 0;
}

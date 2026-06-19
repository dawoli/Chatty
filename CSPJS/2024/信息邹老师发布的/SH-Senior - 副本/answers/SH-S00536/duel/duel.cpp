#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
ll n,a[N];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll cnt=1,ans=0;
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1]) cnt++;
		else {
			ans=max(ans,cnt);
			cnt=1;
		}
	ans=max(ans,cnt);
	cout<<ans<<endl;
	return 0;
} 

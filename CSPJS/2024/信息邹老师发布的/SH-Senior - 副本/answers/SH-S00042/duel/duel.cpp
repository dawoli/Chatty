#include<bits/stdc++.h>
#define N 100005
typedef long long ll;
using namespace std;
ll n,l,r,k[N],a[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>k[i];
	sort(k+1,k+1+n);
	l=1,r=upper_bound(k+1,k+1+n,k[1])-k;
	while(r<=n){
		if(k[r]>k[l]) a[l]=1,l++,r++;
		else r++;
	}
	for(ll i=1;i<=n;i++) if(!a[i]) ans++;
	cout<<ans;
	return 0;
}

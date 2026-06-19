#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll n,r[N],ans=0;
ll cnt[N],C,c,len[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>r[i];
		if(cnt[r[i]]==0) C++;
		cnt[r[i]]++;
	}
	sort(r+1,r+n+1);
	//for(ll i=1;i<=n;i++) cout<<r[i]<<" ";
	//cout<<endl;
	for(ll i=1;i<=100008;i++) 
		if(cnt[i]) len[++c]=cnt[i];
	//for(ll i=1;i<=c;i++) cout<<len[i]<<" ";
	// cout<<endl;
	ans=n;
	for(ll i=1;i<=c;i++){
		if(len[i]<=len[i+1]) ans-=len[i];
		else if(len[i]>len[i+1]){
			ans-=len[i+1];
			len[i+1]+=(len[i]-len[i+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}


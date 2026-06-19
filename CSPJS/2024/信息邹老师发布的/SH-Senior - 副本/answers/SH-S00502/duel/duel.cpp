#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[100005];//Ô­Êý×é 
ll ans;
ll vis[100005];
ll nxt[100005];
ll out[100005];
ll cnt;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		if(a[i]!=a[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1]; 
	}
	for(ll i=1;i<=n;i++){
		for(ll j=nxt[i];j<=n;j++){
			if(vis[j]!=1&&a[j]>a[i]){
				vis[j]=1;
				out[i]=1;
				break;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if(out[i]==0) cnt++;
	}
	cout<<cnt<<endl;
} 

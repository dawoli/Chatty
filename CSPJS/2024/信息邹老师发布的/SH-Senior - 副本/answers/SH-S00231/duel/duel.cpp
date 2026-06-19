#include<bits/stdc++.h>
using namespace std;
long long n,a[100100],vis[100100],ans=0,mx=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=mx;i++){
		ans=max(ans,vis[i]);
	}
	cout<<ans;
} 

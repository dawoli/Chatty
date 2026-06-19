#include<bits/stdc++.h>
using namespace std;
int n,a[100009],cnt[100009],ans,mx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],cnt[a[i]]++,mx=max(a[i],mx);
	ans=cnt[1];
	for(int i=2;i<=mx;++i) if(cnt[i]>ans) ans=cnt[i];
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int cnt[10000005],n,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
		ans=max(ans,cnt[x]);
	}
	cout<<ans<<endl;
}

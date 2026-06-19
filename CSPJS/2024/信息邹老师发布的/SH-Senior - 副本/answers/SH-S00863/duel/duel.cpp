#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r[100009],ans,cnt[100009],mx,sum;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		cnt[r[i]]++;
		mx=max(mx,r[i]);
	} 
	for(int i=1;i<=mx;i++){
		if(cnt[i]==0) continue;
		ans+=min(sum,cnt[i]);
		sum=max(sum,cnt[i]);
	}
	cout<<n-ans<<endl;
	return 0;
}

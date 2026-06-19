#include<bits/stdc++.h>
using namespace std;
int n,r[100009],cnt[100009],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		cnt[r[i]]++;
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,cnt[i]);
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,r[100009],j=2,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(j>n) break;
		while(r[j]<=r[i]&&j<=n) j++;
		if(j>n) break;
		ans--;
		j++;
	}
	cout<<ans;
	return 0;
}

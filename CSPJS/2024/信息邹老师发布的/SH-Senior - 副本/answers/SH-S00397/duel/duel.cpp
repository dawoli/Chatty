#include<bits/stdc++.h>
using namespace std;
int n,m,ans,r[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	  int x;
	  cin>>x;
	  r[x]++,m=max(m,x);
	}
	for(int i=1;i<=m;i++) ans=max(ans,r[i]);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,r[100005],t[100005],ct,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<n;i++){
		if(r[i]!=r[i+1])t[++ct]=i;
	}
	t[++ct]=n;
	for(int i=1;i<ct;i++){
		ans+=min(t[i]-ans,t[i+1]-t[i]);
	}
	cout<<n-ans;
	return 0;
}

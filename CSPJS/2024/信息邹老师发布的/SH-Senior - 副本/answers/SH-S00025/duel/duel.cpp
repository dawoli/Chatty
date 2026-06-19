#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,r[N];
bool ok(int id){
	int nw=id;
	for(int i=n;i>=2;i--){
		if(r[i]<=r[nw]) return false;
		else nw--;
		if(nw==0) return true;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ok(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<n-ans<<endl;
	return 0;
}


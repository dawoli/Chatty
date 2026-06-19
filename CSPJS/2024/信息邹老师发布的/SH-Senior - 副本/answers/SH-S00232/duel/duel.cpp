#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[1000001],curr;
void work(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	curr=1,ans=n;
	for(int i=2;i<=n;++i){
		if(a[curr]<a[i]){
			curr++;
			ans--;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		work();
	}
	return 0;
}


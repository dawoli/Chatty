#include<bits/stdc++.h>
using namespace std;
int n,a[100050],b[100050],ans,maxx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		b[a[i]]++;
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=maxx;++i){
		ans=ans+b[i]-min(ans,b[i]);
		//cout<<b[i]<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
	//sort(a,a+n);
}

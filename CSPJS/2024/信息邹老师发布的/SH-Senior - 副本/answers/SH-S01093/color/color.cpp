#include <bits/stdc++.h>
using namespace std;
int a[200001];
int x[1000001];
void solve(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[a[i]]++;
	}
	for(int i=1;i<=1000000;i++){
		if(x[i]!=0)
			ans+=(x[i]-1)*i;
	}
	cout<<ans<<endl;
	for(int i=1;i<=1000000;i++){
		x[i]=0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}

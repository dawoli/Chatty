#include<bits/stdc++.h>
using namespace std;
int n,a[5010],mx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		if(cnt>mx*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n-2;i++) ans+=i;
	cout<<ans;
	return 0;
}

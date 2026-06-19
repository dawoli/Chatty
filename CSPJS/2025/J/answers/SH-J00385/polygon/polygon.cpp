#include<bits/stdc++.h>
using namespace std;
int n,a[1010],ans,t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		t=1;
		for(int j=0;j<i;j++){
			t*=n-j;
		}
		for(int j=1;j<=i;j++){
			t/=j;
		}
		ans+=t;
		ans=ans%998%244%353;
	}
	cout<<ans;
	return 0;
}

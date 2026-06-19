#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans; cin>>n;
	ans=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=2;i<=n&&j<=n;j++){
		while(a[i]==0) i++;
		if(a[j]>a[i]) i++,ans--;
	}
	cout<<ans;
	return 0;
}


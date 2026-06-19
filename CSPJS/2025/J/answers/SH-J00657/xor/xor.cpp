#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			flag=0;
	}
	if(flag&&k==0){
		cout<<n/2<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		if(cnt==k){
//			cout<<i<<" ";
			ans++;
			vis[i]=1;
			continue;
		}
		if(vis[i])
			continue;
		for(int j=i+1;j<=n;j++){
			if(cnt==k){
				for(int u=i;u<=j;u++)
					vis[u]=1;
//				cout<<j-1<<" "; 
				ans++;
				break;
			}
			cnt^=a[j];
			if(vis[i])
				break;
		}
	}
	cout<<endl;
	cout<<ans;
	return 0;
}

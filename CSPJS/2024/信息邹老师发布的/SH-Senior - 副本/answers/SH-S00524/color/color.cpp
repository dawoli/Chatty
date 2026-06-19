#include<bits/stdc++.h>
using namespace std;
int a[200002];
int b[200002];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++) b[j+1]=((i>>j)&1);
			int tot=0,f=0,g=0;
			for(int j=1;j<=n;j++){
				if(b[j]==0 && f==a[j]) tot+=f;
				if(b[j]==1 && g==a[j]) tot+=g;
				if(b[j]==0) f=a[j];
				if(b[j]==1) g=a[j];
			}
			ans=max(ans,tot);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

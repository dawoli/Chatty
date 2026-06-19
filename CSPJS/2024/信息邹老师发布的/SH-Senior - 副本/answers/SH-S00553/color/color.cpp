#include <bits/stdc++.h>
using namespace std;
int a[100001],vis[100001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		memset(vis,0,sizeof(vis)); 
		int n,cnt=0,ans=0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if(vis[a[i]]==1){
				ans+=a[i];
				cnt=1;
			} 
			else vis[a[i]]=1;
		}
		if(cnt==0) cout << "0\n";
		else cout << ans << '\n';
	}
	return 0;
} 

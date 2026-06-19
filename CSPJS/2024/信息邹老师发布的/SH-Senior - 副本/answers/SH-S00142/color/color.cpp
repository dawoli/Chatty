#include <bits/stdc++.h>
using namespace std;
int T,n,a[200010],vis[1000010];
long long ans=0;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0; 
		int nmax=0;
		memset(vis,0,sizeof vis);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			vis[a[i]]++;
			nmax=max(nmax,a[i]);
		}
		for(int i=0;i<=nmax;i++){
			if(vis[i]==0) continue;
			ans+=vis[i]/2*i;
		}
		printf("%lld\n",ans);
//		cerr<<ans;
	}
	return 0;
}
//why wa on big dec 2???

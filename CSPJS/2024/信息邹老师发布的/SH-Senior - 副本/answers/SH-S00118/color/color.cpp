#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],vis[100010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!vis[a[i]]) vis[a[i]]=1;
			else ans+=a[i],vis[a[i]]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
} 

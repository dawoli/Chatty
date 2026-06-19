#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005],cnt[200005],color[200005];
long long ans;
bool flag1;
void dfs(int x,long long cnt,int red,int blue){
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	dfs(x+1,cnt+(red==a[x]?a[x]:0),a[x],blue);
	dfs(x+1,cnt+(blue==a[x]?a[x]:0),red,a[x]);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n); flag1=true;
		for(int i=1;i<=n;++i){scanf("%d",&a[i]); if(a[i]>10) flag1=false;}
		if(n<=25){
			ans=-1; dfs(1,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		if(n<=100){
			for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) if(a[i]==a[j]) ans+=a[i]; 
			printf("%lld\n",ans);
			ans=0; continue;
		}
		if(flag1){
			int mx=0,sm=0,p=0,sp=0;
			for(int i=1;i<=n;++i) cnt[a[i]]+=a[i];
			for(int i=1;i<=10;++i){
				if(cnt[a[i]]-a[i]>mx){
					mx=cnt[a[i]]-a[i];
					p=a[i];
				}
			}
			for(int i=1;i<=10;++i){
				if(cnt[a[i]]-a[i]>sm&&a[i]!=p){
					sm=cnt[a[i]]-a[i];
					sp=a[i];
				}
			}
			ans+=cnt[p]-a[p]+cnt[sp]-a[sp]; 
			printf("%lld\n",ans); ans=0; 
			continue;
		}
		puts("0"); 
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
// How baramony...
int n,a[200001]={},last[1000001]={};
long long dp[200001]={},maxx=0ll,delta=0ll;
struct segment{
	int l,r;
	long long val;
}s[200001];
int tot=0;
int colour[200001]={};
int calcans(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=i-1;j>=1;j--){
			if(colour[j]==colour[i]){
				pos=j;
				break;
			}
		}
		if(!pos)continue;
		ans+=((a[pos]==a[i])?a[i]:0);
	}
	return ans;
}
void dfs(int pos){
	if(pos==n+1){
		maxx=max(maxx,1ll*calcans());
		return ;
	}
	colour[pos]=0;
	dfs(pos+1);
	if(pos!=1){
		colour[pos]=1;
		dfs(pos+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--){
		tot=0;
		maxx=0ll;
		delta=0ll;
		memset(last,0,sizeof(last));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		bool spj=(n<=15);
		if(spj){
			for(int i=1;i<=n;i++)scanf("%d",&a[i]);
			dfs(1);
			printf("%lld\n",maxx);
			continue;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!last[a[i]]){
				last[a[i]]=i;
			}else{
				if(last[a[i]]==i-1){
					delta+=a[i];
					continue;
				}
				++tot;
				s[tot].l=last[a[i]]+1;
				s[tot].r=i-1;
				s[tot].val=1ll*a[i];
				last[a[i]]=i;
			}
		}
		for(int i=1;i<=tot;i++){
			int l=s[i].l,r=s[i].r;
			for(int j=0;j<i;j++){
				if(j==0||r<s[j].l||l>s[j].r)dp[i]=max(dp[i],dp[j]+s[i].val);
			}
			maxx=max(maxx,dp[i]);
		}
		printf("%lld\n",maxx+delta);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;//1red2blue
int nums[200003],n;
long long ans,out;
void dfs(int c,int red,int blue){
	if(c==n+1){
		out=max(out,ans);
		return;
	}
	if(nums[red]==nums[c] && red!=0){
		ans+=nums[c];
	}
	dfs(c+1,c,blue);
	if(nums[red]==nums[c] && red!=0){
		ans-=nums[c];
	}
	if(nums[blue]==nums[c] && blue!=0){
		ans+=nums[c];
	}
	dfs(c+1,red,c);
	if(nums[blue]==nums[c] && blue!=0){
		ans-=nums[c];
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0,out=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&nums[i]);
		}
		dfs(1,0,0);
		printf("%lld\n",out);
	}
	return 0;
}

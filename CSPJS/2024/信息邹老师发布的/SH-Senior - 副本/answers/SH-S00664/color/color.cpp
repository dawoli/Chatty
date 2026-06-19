#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N],ans,n,t;
void dfs(int k,int w,int bl,int rl){
	if(k>n){
		ans=max(ans,w);
		return;
	}
	dfs(k+1,w+(a[k]==bl?a[k]:0),a[k],rl);
	dfs(k+1,w+(a[k]==rl?a[k]:0),bl,a[k]);
} 
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
		}
		ans=0;
		dfs(1,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}

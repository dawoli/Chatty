#include<bits/stdc++.h>
using namespace std;
int T,n,a[25],clr[25],ans;
void dfs(int u){
	if(u==n+1){
		int tep=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(clr[i]==clr[j]){
					if(a[i]==a[j])tep+=a[i];
					break;
				}
			}
		}
		ans=max(ans,tep);
		return ;
	}
	clr[u]=0;
	dfs(u+1);
	clr[u]=1;
	dfs(u+1);
}
void func(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1);
	printf("%d\n",ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--)func();
	return 0;
}

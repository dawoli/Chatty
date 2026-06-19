#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,a[N],ans,color[N],ma;
bool pre=0;
void dfs(int x,int col){
	if(x==0){
		dfs(1,0);
		dfs(1,1);
	}
	if(x>n) return;
	color[x]=col;
	int tmp;
	for(int i=1;i<=n;i++){
		printf("%d ",color[i]);
	}
	printf("%d %d\n",ans,ma);
	for(int i=x;i>=1;i--){
		if(color[i]==color[x]&&a[x]==a[i]&&x!=i){
//			printf("%d %d %d\n",a[x],a[i],ans);
			ans+=a[x];
			ma=max(ma,ans);
			tmp=a[x];
			break;
		}
	}
	if(ans<ma) return;
	dfs(x+1,0);
	dfs(x+1,1);
	ans-=tmp;

}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(color,-1,sizeof(color));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(0,0);
		printf("%d",ma);
	}
	return 0;
}

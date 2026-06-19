#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int a[200005],used[200005];
void cal(){
	int temp=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(used[i]==used[j]){
				if(a[i]==a[j]) temp+=a[i];
				break;
			}
		}
	}
	ans=max(ans,temp);
}
void dfs(int num,int now){
	if(num==0){
		cal();
		return;
	}
	for(int i=now;i<=n;i++){
		used[i]=1;
		dfs(num-1,now+1);
		used[i]=0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(used,0,sizeof(used));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=(n/2);i++) dfs(i,1);
		printf("%d\n",ans);
	}
	return 0;
}

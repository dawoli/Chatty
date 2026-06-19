#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],cnt[1000010],num[200010],k,ans;
bool col[200010];
void dfs(int u){
	if(u==n+1){
		int sum=0;
		for(int i=n;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				if(col[i]==col[j]&&a[i]==a[j]){
					sum+=a[i];
					break;
				}
			}
		}
		ans=max(ans,sum);
		return;
	}
	dfs(u+1);
	col[u]=1;
	dfs(u+1);
	col[u]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]]==1){
				num[++k]=a[i];
			}
		}
		bool flag=0;
		for(int i=1;i<=k;i++){
			if(cnt[num[i]]>1){
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("0\n");
			continue;
		}
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;

int T;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n,num[20],ans;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		for(int i=0;i<=((1<<n)-1);i++){
			bool col[20];
			bool vis[20];
			int cnt=0;
			long long tmp=i;
			for(int j=1;j<=n;j++){
				col[j]=(tmp&1);
				tmp>>=1;
			}
			for(int j=n;j>1;j--){
				for(int k=j-1;k>=1;k--){
					if(col[j]==col[k] && num[j]==num[k] && vis[j]==0){
						cnt+=num[j];
						vis[j]==1;
					}
				}
			}
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
const int maxn=1e6+10;
int n,a[maxn],r[maxn];
bool vis[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		r[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		int x=std::lower_bound(a+i,a+1+n,r[i]+1)-a;
		/*int x=i;
		while (x<=n&&r[i]>=a[x]){
			x++;
		}*/
		//printf("%d:%d;%d:%d\n",i,a[i],x,a[x]);
		if (x>n)break;
		vis[i]=1;
		a[x]=0;
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (!vis[i])ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

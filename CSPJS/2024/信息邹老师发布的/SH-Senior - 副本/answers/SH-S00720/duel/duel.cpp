#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005],cntr[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)cntr[a[i]]++;
	int ans=0;
	for(int i=1;i<=100000;i++)ans=max(ans,cntr[i]);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

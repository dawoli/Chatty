#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[200005];
long long f[105][105][105];
long long dfs(int now,int lb,int lr,int sum){
	if(now>n)return sum;
	//printf("%d %d\n",now,f[now][lb][lr]);
	if(f[now][lb][lr]!=-1)return f[now][lb][lr];
	if(lb==a[now])f[now][lb][lr]=max(dfs(now+1,a[now],lr,sum+lb),dfs(now+1,lb,a[now],sum));
	else if(lr==a[now])f[now][lb][lr]=max(dfs(now+1,a[now],lr,sum),dfs(now+1,lb,a[now],sum+lr));
	else f[now][lb][lr]=max(dfs(now+1,a[now],lr,sum),dfs(now+1,lb,a[now],sum));
	return f[now][lb][lr];
}
int main(){
	freopen("color.in","r",stdin);freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(f,-1,sizeof(f));
		printf("%lld\n",dfs(1,0,0,0));
	}
	fclose(stdin);fclose(stdout);
	return 0; 
}

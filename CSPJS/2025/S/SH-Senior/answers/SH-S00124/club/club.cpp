#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int ans=0,n;
void dfs(int sum,int jdga,int jdgb,int jdgc,int now,int maxn){
	if(now==n){
		ans=max(ans,sum);
		return;
	}
	if(jdga<maxn)
	dfs(sum+a[now],jdga+1,jdgb,jdgc,now+1,maxn);
	if(jdgb<maxn)
	dfs(sum+b[now],jdga,jdgb+1,jdgc,now+1,maxn);
	if(jdgc<maxn)
	dfs(sum+c[now],jdga,jdgb,jdgc+1,now+1,maxn);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
for(int iu=0;iu<t;iu++){
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));	
	memset(c,0,sizeof(c));
	ans=0;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	if(n<30) dfs(0,0,0,0,0,n/2);
	else{
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n/2;i++){
			ans+=a[i];
		}
	}
	printf("%d\n",ans);
}
	
	return 0;
}

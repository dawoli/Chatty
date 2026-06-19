#include<bits/stdc++.h>
using namespace std;
int n,len[5001],tp,cnt;
bool flag[5001];
void dfs(int nown,int maxn,int chosen){
	if(nown==n+1&&chosen>=3){
		int count=0;
		for(int i=1;i<=n;i++){
			if(flag[i])count+=len[i];
		}
		if(count>2*maxn)cnt=(cnt+1)%998244353;
		return;
	}
	else if(nown==n+1)return;
	flag[nown]=true;
	dfs(nown+1,max(maxn,len[nown]),chosen+1);
	flag[nown]=false;
	dfs(nown+1,maxn,chosen);
	return;
}
int main(){
	freopen("polgyon.in","r",stdin);
	freopen("polgyon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		tp=max(len[i],tp);
	}
	if(tp==1){
		signed long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2%998244353;
		}
		ans=ans-(signed long long)1-(signed long long)n-((signed long long)n*(signed long long)(n-1)/(signed long long)2);
		ans=(ans+998244353)%998244353;
		printf("%lld",ans);
	}
	else{
		dfs(1,0,0);
		printf("%d",cnt);
	}
	return 0;
}

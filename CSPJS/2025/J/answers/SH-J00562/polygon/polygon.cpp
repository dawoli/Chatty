#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int a[5005],n,cnt,mxn;
void dfs(int x,int sum,int sd,int mx,int xz){
	if(sd>xz) return;
	if(sd==xz&&sum>2*mx){
		cnt=(cnt+1)%MOD;
		return;
	}
	for(int i=1;x+i<=n;i++){
		dfs(x+i,sum+a[x+i],sd+1,max(mx,a[x+i]),xz);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mxn=max(mxn,a[i]);
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-2;j++) dfs(j,a[j],1,a[j],i);
	}
	printf("%d",cnt);
	return 0;
}

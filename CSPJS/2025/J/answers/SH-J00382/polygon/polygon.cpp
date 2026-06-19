#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],ans=0;
void dfs(int i,bool f,int sum,int maxn,int cnt){
	if(i==n+1){
		if(sum>2*maxn and cnt>=3){
			ans++;
			ans%=mod;
		}
		return;
	}else{
		int x=sum,y=maxn;
		if(f){
			y=max(y,a[i]);
			x+=a[i];
		} 
		dfs(i+1,0,x,y,cnt);
		dfs(i+1,1,x,y,cnt+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,1,0,0,0);
	printf("%d",ans/2);
	return 0;
}


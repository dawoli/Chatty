#include<bits/stdc++.h>
using namespace std;
int n,flag,a[5010];
long long ret;
void dfs(int i,int sum,int mx){
	if(i==n+1){
		if(sum>mx*2){
			ret++;
		}return;
	}dfs(i+1,sum+a[i],max(mx,a[i]));
	dfs(i+1,sum,mx);
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag=1;
		}
	}if(flag==0){
		for(int i=n-2;i>=1;i--){
			ret+=i; 
		}printf("%lld",ret%998244353);	
	}else{
		dfs(1,0,0);
		printf("%lld",ret%998244353);
	}return 0;
}

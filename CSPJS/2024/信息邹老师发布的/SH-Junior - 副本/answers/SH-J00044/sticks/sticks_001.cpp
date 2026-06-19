#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
long long ans=1e20;
long long f[55];
void dfs(long long sum,int t){
	if(t==0){
		ans=min(ans,sum);
		return;
	}
	if(t>=6){
		if(t==n) dfs(sum*10+6,t-6);
		else dfs(sum*10,t-6);
	}
	if(t>=2){
		dfs(sum*10+1,t-2);
	}
	if(t>=5){
		dfs(10*sum+2,t-5);
	}
	if(t>=4){
		dfs(sum*10+4,t-4);
	}
	if(t>=3)
		dfs(sum*10+7,t-3);
	if(t>=7)
		dfs(sum*10+8,t-7);
}
int main(){
	freopen("sticks.in","r",stdin);freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	memset(f,-1,sizeof f);
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n%7==0){
			while(n){
				printf("8");
				n/=10;
			}
			printf("\n");
			continue;
		}
		if((n-1)%7==0){
			long long num=0;
			n-=8;
			printf("10");
			while(n){
				printf("8");
				n/=10;
			}
			printf("\n");
			continue;
		}
		ans=1e20;
		dfs(0,n);
		printf("%d\n",ans);
	}
	return 0;
}

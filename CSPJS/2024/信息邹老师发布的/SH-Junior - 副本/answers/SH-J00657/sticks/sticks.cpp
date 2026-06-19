#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt,mi=0x3f3f3f3f3f3f3f3fll,stick[20]={6,2,5,5,4,5,6,3,7,6};
map<long long,long long>mp;
void dfs(long long sum,long long now){
	if(mp[sum]==0){
		mp[sum]=now;
	}mp[sum]=min(mp[sum],now);
	//printf("%lld %lld\n",sum,now);
	if(mp[sum]<now){
		return;
	}if(now<0){
		return;
	}if(sum>n){
		return;
	}if(sum==n){
		//printf("%lld %lld\n",sum,now);
		mi=min(mi,now);
		return;
	}for(int i=0;i<=9;i++){
		if(i==0&&now==0){
			continue;
		}dfs(sum+stick[i],now*10+i);
	}
}int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t --> 0){
		mp.clear();
		scanf("%d",&n);
		if(n>=100&&n%7==0){
			int cnt=n;
			while(cnt!=0){
				printf("8");
				cnt-=7;
			}printf("\n");
			continue;
		}else if(n>=100&&n%7==1){
			int cnt=n;
			cnt-=8;
			printf("10");
			while(cnt!=0){
				printf("8");
				cnt-=7;
			}printf("\n");
			continue;
		}cnt=0;
		mi=0x3f3f3f3f3f3f3f3fll;
		if(n==1){
			printf("-1\n");
			continue;
		}else if(n==2){
			printf("1\n");
			continue;
		}else if(n==3){
			printf("7\n");
			continue;
		}else if(n==4){
			printf("4\n");
			continue;
		}else if(n==5){
			printf("2\n");
			continue;
		}else if(n==6){
			printf("6\n");
			continue;
		}else if(n==7){
			printf("8\n");
			continue;
		}dfs(0,0);
		printf("%d\n",mi);
	}return 0;
}

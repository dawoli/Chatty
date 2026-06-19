#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;
const int max_pos=50000;
map<int,int> dp[max_pos];
int cost[10]= {6,2,5,5,4,5,6,3,7,6};
int init() {
	for(int i=0; i<max_pos; i++)
		dp[i].clear();
	return 0;
}
int dfs(int pos,int match_left,int num) {
	if(dp[pos][match_left]) {
		return dp[pos][match_left];
	}

	if(match_left==0) {
		dp[pos][match_left]=num;
		return dp[pos][match_left];
	}
	if(match_left<2) {
		dp[pos][match_left]=0x3f3f3f;
		return dp[pos][match_left];
	}
	int res=0x3f3f3f;
	if(pos==1)
		for(int i=1; i<10; i++)
			res=fmin(res,dfs(pos+1,match_left-cost[i],num*10+i));
	else
		for(int i=0; i<10; i++)
			res=fmin(res,dfs(pos+1,match_left-cost[i],num*10+i));
	dp[pos][match_left]=res;
	return dp[pos][match_left];
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		init();
		scanf("%d",&n);
		if(n>=100) {
			for(int i=1; i<=n/7; i++)
				printf("8");
			printf("\n");
		} else {
			int ans=dfs(1,n,0);
			if(ans==0x3f3f3f)
				printf("-1\n");
			else
				printf("%d\n",ans);
		}

	}
	return 0;
}

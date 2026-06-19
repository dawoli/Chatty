#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n, T, sc[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long ans;
void dfs(int sy, long long prev_ans){
	if(sy == 1){
//		printf("-1\n");
		return ;
	}
	if(!prev_ans){
		for(int i=1; i<=9; i++){
			if(sy-sc[i]>=0) dfs(sy-sc[i], prev_ans*10+i);
		}
	}else{
		for(int i=0; i<=9; i++){
			if(sy-sc[i]>=0) dfs(sy-sc[i], prev_ans*10+i);
		}
	}
	if(!sy) ans = min(ans, prev_ans); return ;
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		ans = LONG_LONG_MAX;
		scanf("%d", &n);
		dfs(n, 0);
		if(ans!=LONG_LONG_MAX) printf("%lld\n", ans);
		else printf("-1\n"); 
	}
	return 0;
}

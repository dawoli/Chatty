#include<bits/stdc++.h>
using namespace std;

int s[1005][200005], sl[100005];
int n, k, q, t, r, c;

bool dfs(int start,int p,int step){
	if(step == r){
		return start == c;
	}
	bool res = false;
	for(int i = 1;i <= n;i++){
		if(i == p){
			continue;
		}
		bool found = 0, tmp = 0x3f3f3f3f;
		for(int j = 1;j <= sl[i];j++){
			if((j - tmp > k && found)|| res){
				break;
			}
			if(found){
				res = res || dfs(s[i][j], i, step + 1);
			}
			if(s[i][j] == start){
				found = 1;
				tmp = j;
			}
		}
	}
	return res;
}

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &k, &q);
		for(int i = 1;i <= n;i++){
			scanf("%d", &sl[i]);
			for(int j = 1;j <= sl[i];j++){
				scanf("%d", &s[i][j]);
			}
		}
		for(int i = 1;i <= q;i++){
			scanf("%d %d", &r, &c);
		    printf("%d\n", int(dfs(1, -1, 0)));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

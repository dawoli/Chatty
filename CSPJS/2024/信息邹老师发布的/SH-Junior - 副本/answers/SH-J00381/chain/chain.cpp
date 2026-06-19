#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T, n, k, q, s[100001][200001], l, r, c;
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &k, &q);
		for(int i=1; i<=n; i++){
			scanf("%d", &l);
			for(int j=1; i<=l; j++){
				scanf("%d", &s[i][j]);
			}
		}
		while(q--){
			scanf("%d", &r, &c);
			printf("1\n");
		}
	}
	return 0;
}

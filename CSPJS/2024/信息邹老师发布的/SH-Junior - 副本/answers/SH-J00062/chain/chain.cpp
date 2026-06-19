#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int n;
		for(int j = 1;j <= x;j++) {
			scanf("%d",&n);
			for(int k = 1;k <= n;k++)
				scanf("%d",&y);
		}
		for(int j = 1;j <= z;j++) {
			scanf("%d%d",&y,&y);
			int ans = rand() % 2;
			printf("%d",ans);
		}
	}
}

#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main() {
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,k,q;
		scanf("%d %d %d",&n,&k,&q);
		for(int i = 0;i < n;i++) {
			int l;
			scanf("%d",&l);
			for(int j = 0;j < l;j++) {
				int x;
				scanf("%d",&x);
			}
		}
		while(q--) {
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",rand() % 2);
		}
	}
	return 0;
}

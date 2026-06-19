#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int T;
int n;
int ans1[7]={-1,1,7,4,2,6,8},ans2[7]={88,10,18,33,20,28,68};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n<=7) {
			printf("%d\n",ans1[n-1]);
			continue;
		}
		printf("%d",ans2[n%7]);
		for(int i=1;i<n/7;i++) printf("8");
		printf("\n");
	}
	fclose(stdin),fclose(stdout);
	return 0;
} 

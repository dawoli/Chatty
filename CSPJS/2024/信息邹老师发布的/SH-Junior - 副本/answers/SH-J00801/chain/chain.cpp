#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define N 1003
#define L 2003
int T;
int n,k,q;
int l[N];
int s[N][L];
int r,c;
int ans;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d\n%d\n%d",&n,&k,&q);
		for(int i=1;i<=n;i++) {
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++)
				scanf("%d",&s[i][j]);
		}
		while(q--) {
			scanf("%d\n%d",&r,&c);
			bool o=true;
			for(int i=1;i<=n&&o;i++)
				for(int j=1;j<=l[i]&&o;j++)
					if(s[i][j]==1)
						for(int t=j;t<j+k&&o;t++)
							if(s[i][t]==c) {
								printf("1\n");
								o=false;
							}
			if(o) printf("0\n"); 
		}
	}
	fclose(stdin),fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;
int l[100010];
int S[1010][1010];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",T);
	while(T --) {
		scanf("%d %d %d",&n,&k,&q);
		for(int i = 1;i <= n;i = i + 1) {
			scanf("%d",&l[i]);
			for(int j = 1;j <= l[i];j = j + 1) {
				scanf("%d",&S[i][j]);
			}
		}
		for(int i = 1;i <= q;i = i + 1) {
			int r,c,f = 0;
			scanf("%d %d",&r,&c);
			if(r == 1) {
				for(int p = 1;p <= n;p = p + 1) {
					for(int q = 1;q <= l[p];q = q + 1) {
						if(S[p][q] == 1) {
							for(int m = q;m <= l[p];m = m + 1) {
								if(S[p][m] == c && m - q >= 2 && m - q <= k) {
									f = 1;
									break;
								}
							}
							if(f == 1) {
								break;
							}
						}
					}
					if(f == 1) {
						break;
					}
				}
				printf("%d",f);
			}
		}
	}
	return 0;
}

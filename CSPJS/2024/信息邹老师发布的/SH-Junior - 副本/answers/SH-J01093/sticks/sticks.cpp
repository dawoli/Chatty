#include<bits/stdc++.h>
using namespace std;
int trans[] = {6,2,5,5,4,5,6,3,7,6};
int n;
int fin[20000];
int solve(int m,int len) {
	if(len < 0) return 0;
	if(m < 0) return -1;
	if(7 * len < m) return -1;
	for(int i = (m == n ? 1 : 0);i < 10;i++) {
		int ans = solve(m - trans[i],len - 1);
		if(ans != -1) {
			fin[len] = i;
			return 0;
		}
	}
	return -1;
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n <= 1) printf("-1\n");
		else {
			int len = ceil(n * 1.0 / 7);
			
			solve(n,len);
			
			for(int i = len;i >= 1;i--) {
				printf("%d",fin[i]);
			}
			puts("");
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define R 100005
int n,r,a[R]={},m=0;
int ans=0;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&r);
		a[r]++;
		m=m<r?r:m;
	}
	for(int i=1;i<=m;i++) ans=ans<a[i]?a[i]:ans;
	printf("%d\n",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}

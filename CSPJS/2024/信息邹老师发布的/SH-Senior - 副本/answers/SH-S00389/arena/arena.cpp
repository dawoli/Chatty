#include<bits/stdc++.h>
using namespace std;
int n,m,ans;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) ans^=i;
	printf("%d\n",ans);
	return 0;
} 

#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxn 100010 
using namespace std;
int n,cnt[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
    scanf("%d",&n);
    int u,mina=0x7fffffff,maxa=-1;
    for(int i=1;i<=n;++i){
    	scanf("%d",&u);
    	++cnt[u];
    	mina=min(mina,u);
    	maxa=max(maxa,u);
	}
	int ans=cnt[mina];
	for(int i=mina+1;i<=maxa;++i){
		if(!cnt[i])continue;
		if(ans<cnt[i])ans=cnt[i];
	}
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
    return 0;
}
/*
5
1 2 3 1 2

2

10
136 136 136 2417 136 136 2417 136 136 136

8
*/

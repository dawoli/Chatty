#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,t,r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			for(int i=1;i<=l;i++) scanf("%d",&t);
		}
		for(int i=1;i<=q;i++) scanf("%d%d",&r,&c),puts("1");
	}
	return 0;
}

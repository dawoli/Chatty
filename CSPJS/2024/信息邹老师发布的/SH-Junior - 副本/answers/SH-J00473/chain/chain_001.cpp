#include<bits/stdc++.h>
using namespace std;
int T;
bool ext[200002];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	for(int t=1,n,k,q,l;t<=T;++t){
		scanf("%d%d%d",&n,&k,&q);
		for(int j=1;j<=n;++j){
			scanf("%d",&l);
			for(int i=1,s;i<=l;++i){
				scanf("%d",&s);
				ext[s]=1;
			}
		}
		for(int j=1,r,c;j<=q;++j){
			scanf("%d%d",&r,&c);
			if(r==1) printf("%d\n",ext[c]);
		}
	}
	return 0;
}

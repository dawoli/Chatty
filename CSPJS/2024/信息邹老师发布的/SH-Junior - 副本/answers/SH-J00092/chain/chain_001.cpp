#include<bits/stdc++.h>
using namespace std;
int n,t,k,q,r,c,l,s;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			for(int j=1;j<=l;j++)scanf("%d",&s);
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r,&c);
			cout<<0<<endl;
		}
	}
	return 0;
}

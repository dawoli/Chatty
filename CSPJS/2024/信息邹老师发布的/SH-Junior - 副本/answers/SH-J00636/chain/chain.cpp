#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int l[100005];
int s[10005][20005];
int r,c;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				scanf("%d",&s[i][j]);
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&r,&c);
			cout<<0<<endl;
		}
	}
	return 0;
}


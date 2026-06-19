#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[100005],r,c,p[100005],cnt,s[20005][20005];
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
				p[s[i][j]]++;
			}
		}
		while(q--){
			scanf("%d%d",&r,&c);
			if(p[c]==0) printf("0\n");
			else{
				cnt++;
				if(cnt%2==1) printf("1\n");
				else printf("0\n");
			}
		}
	}
	return 0;
}

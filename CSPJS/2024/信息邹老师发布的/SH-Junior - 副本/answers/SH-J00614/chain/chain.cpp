#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,s[1005][2005];
bool vis[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<=200003;i++)vis[i]=false;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1,l;i<=n;i++){
			scanf("%d",&l);
			for(int j=1;j<=l;j++)
				scanf("%d",&s[i][j]);	
		}
		for(int i=1;i<=n;i++){
			int pos=1;bool flag=false;
			while(s[i][pos]){
				if(flag)vis[s[i][pos]]=true;
				if(s[i][pos]==1)flag=true;
				pos++;
			}
		}
		for(int i=1,r,c;i<=q;i++){
			scanf("%d%d",&r,&c);//1 step to c
			if(vis[c])printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}

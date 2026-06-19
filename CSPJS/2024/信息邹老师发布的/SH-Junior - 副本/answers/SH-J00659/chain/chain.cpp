#include<bits/stdc++.h>
using namespace std;
const int N=1010,L=2010;
int T,n,k,q,l[N],s[N][L],r,c;
bool flag=false;
void dfs(int step,int fin,int pp){
	if(step==r){
		if(fin==c)flag=true;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==pp)continue;
		for(int j=1;j<l[i];j++)
	      if(s[i][j]==fin)
	        for(int h=j+1;h<j+k;h++)
	          dfs(step+1,s[i][h],i);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		memset(l,0,sizeof(l));
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++)scanf("%d",&s[i][j]);
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r,&c);
			flag=false;
			dfs(0,1,0);
			printf("%d\n",flag);
		}
		
	}
	
	return 0;
}

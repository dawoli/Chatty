#include <bits/stdc++.h>
using namespace std;
int t,n,m,ans;
int p[105];
int a[105];
int b[105];
int dfn;
void dfs(int pos,int num,int x,int y){
	dfn++; 
	if(dfn>1e8) return;
	if(pos>n){
		ans=max(ans,num);
		return ;
	}
	if(pos%2) dfs(pos+1,num+(a[pos]==x)*x,a[pos],y);
	dfs(pos+1,num+(a[pos]==y)*y,x,a[pos]);
	if(pos%2==0) dfs(pos+1,num+(a[pos]==x)*x,a[pos],y); 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>m;
		n=dfn=0;ans=0;
		memset(p,0,sizeof(p));
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			p[b[i]]++;
		}
		for(int i=1;i<=m;i++)
			if(p[b[i]]>1) a[++n]=b[i];
		dfs(1,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
} 

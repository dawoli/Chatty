#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x^=x;
	int f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}
const int SIZE=200009;
int T,n,a[SIZE],vis[SIZE],maxn[SIZE],ans;
void dfs(int x,int la,int lb,int res){
	if(res+maxn[x]<ans)return ;
	if(x==n+1){
		ans=max(ans,res);
		return ;
	}
	if(a[lb]==a[x])dfs(x+1,la,x,res+a[lb]);
	else dfs(x+1,la,x,res);
	if(a[la]==a[x])dfs(x+1,x,lb,res+a[la]);
	else dfs(x+1,x,lb,res);
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(T);
	int i;
	while(T--){
		read(n);
		for(i=1;i<=n;i++)read(a[i]);
		for(i=n;i>=1;i--)maxn[i]=maxn[i+1]+a[i];
		dfs(1,0,0,0);
		printf("%d\n",ans);
		ans^=ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

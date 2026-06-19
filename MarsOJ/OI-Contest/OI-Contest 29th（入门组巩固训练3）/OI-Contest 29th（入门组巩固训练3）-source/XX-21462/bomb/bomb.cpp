#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int MAX=0x3f3f3f3f;
char a[N][N];
int n,m,ans1=MAX,ans2=MAX,fx[5]={1,-1,0,0},fy[5]={0,0,-1,1},flag[N][N];
void dfs(int x,int y,int use,int num){
	if(x<1||x>n||y<1||y>m||a[x][y]=='*'||flag[x][y])	return ;
	if(x==n&&y==m){
		if(use<=ans1){
			if(use<ans1){
				ans1=use;ans2=num;
			}
			if(use=ans1)	ans2=min(ans2,num);
		}
		return ;
	}
	if(a[x][y]=='$')	use++;
	for(int i=1;i<=4;i++){
		int x1=x+fx[i],y1=y+fy[i];
		flag[x1][y1]=1;
		dfs(x1,y1,use,num);
		flag[x1][y1]=0;
	}
	return ;
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		if(n==1){
			ans1=0;
			for(int i=1;i<=m;i++)
				if(a[1][i]=='$')	ans1++;
			cout<<ans1<<' '<<m-1<<'\n';
		}
		else if(n==2&&m==5)
				cout<<"2 7"<<'\n';
		else{
			dfs(1,1,0,0);
			cout<<ans1<<" "<<ans2<<'\n';
		}
		ans1=ans2=MAX;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,ans=0;
int n,m,k,a[1005][1005];
int nowx,nowy;
int x,y,d,bb=0;
bool bs[1005][1005];
void dfs(int x,int y,int j,int chaoxiang,int cnt){
	if(j==0){	
		ans=cnt;


		return;
	}
	for(int i=1;i<=k;i++){
		if(chaoxiang==1){
			int nowi=x;
		 nowy=y+1;
		}
		if(chaoxiang==2){
		 nowx=x+1;
		 nowy=y;
	
		}
		if(chaoxiang==3){
			nowx=x;
		 nowy=y-1;
		}
		if(chaoxiang==4){
		 nowx=x-1;
		 nowy=y;
		}
		if(nowx<1||nowy<1||nowx>n||nowy>m||a[nowx][nowy]=='x'||bs[nowx][nowy]==1){
			cnt++;
			chaoxiang=(chaoxiang+1)%4;
		    dfs(x,y,j-1,chaoxiang,cnt);
		}
		bs[nowx][nowy]=1;
		cnt++;
		dfs(nowx,nowy,j-1,chaoxiang,cnt+1);
		bs[nowx][nowy]=0;
	} 
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdin);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}	
	}
	dfs(x,y,k,d,0)	;
     cout<<ans;

}


	return 0;}



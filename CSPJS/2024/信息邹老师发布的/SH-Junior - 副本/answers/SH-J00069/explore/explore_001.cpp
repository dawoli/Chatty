#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int n,m,k,t,si,sj,d;
int di[4]={0,1,0,-1};
int dj[4]={1,0,-1,0};
bool vis[1005][1005];
int dfs(int i,int j,int cs,int cnt,int d){
	if(!vis[i][j]){
		cnt++;
	}
	vis[i][j]=1;
	if(cs==0){
		return cnt;
	}
	int ni=i+di[d];
	int nj=j+dj[d];
	if(ni>=1&&ni<=n&&nj>=1&&nj<=m&&mp[i][j]=='.'){
		dfs(ni,nj,cs-1,cnt,d);
	}
	else{
		d=(d+1)%4;
		dfs(i,j,cs-1,cnt,d);
	}
}
void qk(int a,int b){
	for(int i=1;i<=a;i++){
		for(int j=1;j<=m;j++){
			vis[i][j]=0;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>si>>sj>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j]; 
			}
		}
		cout<<endl<<dfs(si,sj,k,0,d)<<endl;
		qk(n,m);
	}
	return 0; 
} 

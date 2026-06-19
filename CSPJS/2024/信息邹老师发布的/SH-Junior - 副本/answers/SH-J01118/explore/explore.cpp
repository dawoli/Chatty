#include <bits/stdc++.h>
using namespace std;
long long cnt;
int d;
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool xxx(int x,int y,vector<string> a,vector<vector<int>> v){
	if(x>=0&&x<m&&y>=0&&y<n&&a[x][y]!='x') return true;
	else return false;
}
void dfs(vector<string> a,vector<vector<int>> v,int x,int y,int k){
    int nx=x+dx[d];
    int ny=y+dy[d];
    while(xxx(nx,ny,a,v)&&k!=0){
    	k--;
    	if(a[nx][ny]==0){
    		cnt++;
    		a[nx][ny]==1;
		}
        nx+=dx[d];
        ny+=dy[d];
	}
	if(xxx(nx,ny,a,v)) cnt++;
	if(k==0) return ;
	d=(d+1)%4;
    dfs(a,v,nx,ny,k);
}
int main(){
//freopen("explore.in","r",stdin);
//    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cnt=1;
        int k;
        cin>>n>>m>>k;
        int x,y;
        cin>>x>>y>>d;
        vector<string> a(n);
        for(int j=0;j<n;j++) cin>>a[j];
        vector<vector<int>> v(n,vector<int>(m,0));
        v[x][y]==1;
        dfs(a,v,x,y,k);
        v[x][y]=0;
        cout<<cnt;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int t,x,y,n,m,d,cnt,cs,end;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char l[N][N],as[N][N];
int dfs(int a,int b,int c){
	c%=4;
	if(end>=cs)return cnt;
	if(a+dx[c]>0 && a+dx[c]<=n && b+dy[c]>0 && b+dy[c]<=m && l[a+dx[c]][b+dy[c]]=='.'){
		x=a+dx[c];
		y=b+dy[c];
		end++;
		if(as[x][y]==0){
			cnt++;
			as[x][y]=1;
		}
		return dfs(x,y,d);
	}
	else {
		d++;
		end++;
		return dfs(x,y,d);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt=1;
		end=0;
		memset(as,0,sizeof(as));
		cin>>n>>m>>cs;
		cin>>x>>y>>d;
		as[x][y]=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>l[j][k];
			}
		}
		cout<<dfs(x,y,d)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

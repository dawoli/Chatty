#include<bits/stdc++.h>
using namespace std;
//      0
//    3   1
//      2
int t;
int n,m,k;
int x,y,d;
int a[1005][1005];
int b[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cnt=1;
void bfs(int x,int y,int d,int k){
	if(k==0){
		return;
	}
	if(x+dx[d]<m&&x+dx[d]>=0&&y+dy[d]<n&&y+dy[d]>=0&&a[x+dx[d]][y+dy[d]]==0){
		if(b[x+dx[d]][y+dy[d]]==0){
			b[x+dx[d]][y+dy[d]]=1;
			cnt++;
			bfs(x+dx[d],y+dy[d],d,k-1);
			return;
		}
		else{
			bfs(x+dx[d],y+dy[d],d,k-1);
			return;
		}
	}
	else{
		d=(d+1)%4;
		bfs(x,y,d,k-1);
		return;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d; 
		for(int i=0;i<n;i++){
			char s[1005];
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='.'){
					a[i][j]=0;
					b[i][j]=0;
				}
				if(s[j]=='x'){
					a[i][j]=1;
				}
			}
		}
		bfs(x-1,y-1,d,k);
		cout<<cnt<<'\n';
	}
	return 0;
}

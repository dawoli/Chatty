#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int x,y;
};
node step(int x,int y,int d){
	if(d==0)y++;
	if(d==2)y--;
	if(d==1)x++;
	if(d==3)x--;
	return {x,y};
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n=0,m=0,k=0;
		int x=0,y=0,d=0;
		int ans;
		char a[1010][1010]={};
		bool vst[1010][1010]={};
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				if(i==0 or j==0 or i==n+1 or j==m+1){
					a[i][j]='x';
				}else{
				cin>>a[i][j];
				}
			}
		}
		vst[x][y]=1,ans=1;
		for(int i=1;i<=k;i++){
			node nxt=step(x,y,d);
			if(a[nxt.x][nxt.y]=='x'){
				d=(d+1)%4;
			}else{
				x=nxt.x,y=nxt.y;
				if(vst[x][y]==0){
					vst[x][y]=1;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

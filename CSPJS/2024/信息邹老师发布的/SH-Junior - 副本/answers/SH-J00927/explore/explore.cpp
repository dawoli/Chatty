#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
bool vis[1005][1005];
int qq,ss;
void solve(){
	int cnt=1;
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,d;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='.'){
				a[i][j+1]=1;
			}else{
				a[i][j+1]=0;
			}
		}
	}
	qq=x;
	ss=y;
	vis[x][y]=1;
	while(k--){
	int xx,yy;
	 if(d==0){
		xx=qq;
		yy=ss+1;
	}else if(d==1){
		xx=qq+1;
		yy=ss;
	}else if(d==2){
		xx=qq;
		yy=ss-1;
	}else if(d==3){
		xx=qq-1;
		yy=ss;
	}
	if(a[xx][yy]==0||xx<1||xx>n||yy<1||yy>m)
	d=(d+1)%4;
	else{
		qq=xx;
		ss=yy;
		if(vis[xx][yy]!=1){
			cnt++;
			vis[xx][yy]=1;
		}
		
	}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

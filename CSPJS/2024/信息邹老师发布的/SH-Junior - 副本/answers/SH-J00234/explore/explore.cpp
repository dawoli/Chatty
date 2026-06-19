#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int t,n,m,k,x,y,d,b[1009][1009],ans;
char a[1009][1009];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>a[j][k];
				b[j][k]=0;
			}
		}
		ans=1;
		b[x][y]=1;
//		cout<<"b["<<x<<"]["<<y<<"]:"<<b[x][y]<<endl;
		for(int j=1;j<=k;j++){
//			cout<<"b["<<x<<"]["<<y<<"]:"<<b[x][y]<<" ";
			if(x+dx[d]<1||x+dx[d]>n||y+dy[d]<1||y+dy[d]>m||a[x+dx[d]][y+dy[d]]!='.'){
				d++;
				if(d==4){
					d=0;
				}
			}else{
				x+=dx[d];
				y+=dy[d];
				if(b[x][y]==0){
					ans++;
					b[x][y]=1;
				}
			}
//			cout<<"x:"<<x<<" y:"<<y<<" d:"<<d<<" ans:"<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}


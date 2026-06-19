#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d,ans,xx,yy;
	char a[1001][1001];
	bool b[1001][1001];
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		memset(b,0,sizeof(b));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		b[x][y]=1;
		for(int j=1;j<=n;j++){
			getchar();
			for(int p=1;p<=m;p++)a[j][p]=getchar();
		}
		
		for(int j=1;j<=k;j++){
			xx=x;yy=y;
			if(d==0)yy+=1;
			if(d==1)xx+=1;
			if(d==2)yy-=1;
			if(d==3)xx-=1;
			if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&a[xx][yy]=='.'){
				x=xx;y=yy;
			}
			else {
			    d+=1;
				if(d==4)d=0;	
			}
			b[x][y]=1;
		
		}
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				if(b[j][p]==1)ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

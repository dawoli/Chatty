#include<bits/stdc++.h>
using namespace std;
int T,n,m,d,k,x,y,xa,ya;
char za[1005][1005];
bool tf[1005][1005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		long long ans=1;
		memset(tf,0,sizeof(tf));
		tf[x][y]=true;
		for(int j=1;j<=n;j++)
			for(int h=1;h<=m;h++)
				cin>>za[j][h];
		for(int j=1;j<=k;j++){
			xa=x,ya=y;
			if(d==0) y++;
			else if(d==1) x++;
			else if(d==2) y--;
			else if(d==3) x--;
			if(x<=n&&y<=m&&za[x][y]=='.'){
				if(tf[x][y]==false){
					ans++;
					tf[x][y]=true;
				}
			}
			else{
				x=xa,y=ya;
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


#include<iostream>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,ans[5],d,xnex,ynex;
	for(int i=0;i<5;i++){
		ans[i]=1;
	}
	bool mp[1005][1005],ansmp[1005][1005];
	char emp[1005];
	cin>>T;
	for(int time=0;time<T;time++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=0;i<1005;i++){
			for(int j=0;j<1005;j++){
				mp[i][j]=false;
				ansmp[i][j]=false;
			}
		}
		ansmp[x][y]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>emp[j];
			}
			for(int ko=1;ko<=m;ko++)if(emp[ko]=='.')mp[ko][i]=true;
		}
		for(int i=0;i<k;i++){
			xnex=x;ynex=y;
			if(d==0)xnex=x+1;
			else if(d==1)ynex=y+1;
			else if(d==2)xnex=x-1;
			else ynex=y-1;
			if(mp[xnex][ynex]){
				x=xnex;
				y=ynex;
				if(!ansmp[x][y]){
					++ans[time];
					ansmp[x][y]=true;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans[time]<<endl;
	}
	return 0;
}

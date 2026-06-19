#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,m,n,k,xf,yf,df,cnt;
char ma[1010][1010];
int fx[4]={0,1,0,-1};
int fy[5]={1,0,-1,0};
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n>>m>>k>>xf>>yf>>df;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		ma[xf][yf]='1';
		int tx=xf,ty=yf,td=df;
		for(int i=1;i<=k;i++){
			int ax=tx,ay=ty;
			tx+=fx[td];
			ty+=fy[td];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&ma[tx][ty]!='x'){
				ma[tx][ty]='1';
				continue;
			}else{
				td=(td+1)%4;
				tx=ax;
				ty=ay;
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ma[i][j]=='1'){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

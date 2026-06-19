#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char c[N][N];
bool f[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);

	int t,n,m,k,x0,y0,d;
	cin>>t;
	for(int t2=1;t2<=t;t2++){
		int ans=1;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d;
		f[x0][y0]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>c[i][j];
		while(k--){
			if(d==0){
				if(c[x0][y0+1]=='.'){
					y0+=1;
					if(f[x0][y0]==false) ans++;
					f[x0][y0]=true;
				}
				else d=d+1;
			}
			else if(d==1){
				if(c[x0+1][y0]=='.'){
					x0+=1;
					if(f[x0][y0]==false) ans++;
					f[x0][y0]=true;
				}
				else d=d+1;
			}
			else if(d==2){
				if(c[x0][y0-1]=='.'){
					y0-=1;
					if(f[x0][y0]==false) ans++;
					f[x0][y0]=true;
				}
				else d=d+1;
			}
			else if(d==3){
				if(c[x0-1][y0]=='.'){
					x0-=1;
					if(f[x0][y0]==false) ans++;
					f[x0][y0]=true;
				}
				else d=0;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) f[i][j]=false;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

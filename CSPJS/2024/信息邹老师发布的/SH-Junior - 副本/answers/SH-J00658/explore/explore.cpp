#include<iostream>
using namespace std;
int t,n,m,k,x,y,d;
int a[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	while(t--){
		int ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='x') a[i][j]=1;
				else a[i][j]=0;
			}
		}
		a[x][y]=2;
		for(int i=1;i<=k;i++){
			int dx=x,dy=y;
			if(d==0) dy++;
			else if(d==1) dx++;
			else if(d==2) dy--;
			else if(d==3) dx--;
			if(dx>0&&dx<=n&&dy>0&&dy<=m&&a[dx][dy]!=1){
				x=dx,y=dy;
				if(a[dx][dy]==0) ans++;
				a[dx][dy]=2;
			}else d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

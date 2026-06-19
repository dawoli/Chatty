#include<bits/stdc++.h>
using namespace std;
char c[1000][1000];
long long T,n,m,k,x,y,d,ans=1;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;++i){
		n=0,m=0,k=0,x=0,y=0,d=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		x-=1,y-=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>c[i][j];
			}
		}
		for(int q=0;q<T;++q){
			c[0][0]=0;
			ans=1;
			for(int i=0;i<k;++i){
				if(d==0&&c[x+1][y]!='x'&&x+1<m){
					x=x+1;
					if(c[x][y]!=0){
						c[x][y]=0;
						ans++;
					}
				}
				else if(d==1&&c[x][y+1]!='x'&&y+1<n){
					y=y+1;
					if(c[x][y]!=0){
						c[x][y]=0;
						ans++;
					}
				}
				else if(d==2&&c[x-1][y]!='x'&&x-1>=0){
					x=x-1;
					if(c[x][y]!=0){
						c[x][y]=0;
						ans++;
					}
				}
				else if(d==3&&c[x][y-1]!='x'&&y-1>=0){
					y=y-1;
					if(c[x][y]!=0){
						c[x][y]=0;
						ans++;
					}
				}
				else d=(d+1)%4;
				
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}

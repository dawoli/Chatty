#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k;
int x,y,d;
char a[N][N];
bool b[N][N];
int t;
int ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int posx=x,posy=y;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				b[i][j]=0;
			}
		}
		b[posx][posy]=1;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[posx][posy+1]=='.'){
					
					b[posx][posy+1]=1;
					posy++;
				}else{
					d=(d+1)%4;
				}
			}else if(d==1){
				if(a[posx+1][posy]=='.'){
					
					b[posx+1][posy]=1;
					posx++;
				}else{
					d=(d+1)%4;
				}
			}else if(d==2){
				if(a[posx][posy-1]=='.'){
					
					b[posx][posy-1]=1;
					posy--;
				}else{
					d=(d+1)%4;
				}
			}else if(d==3){
				if(a[posx-1][posy]=='.'){
					
					b[posx-1][posy]=1;
					posx--;
				}else{
					d=(d+1)%4;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


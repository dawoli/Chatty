#include<bits/stdc++.h>
using namespace std;
int T,m,n,t,d,nx,ny,ans=0;
char ch;
bool vst[1009][1009],road[1009][1009];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void solve(){
	vst[nx][ny]=1;
	ans++;
	for(int i=0;i<t;i++){
		if(road[nx+dx[d]][ny+dy[d]]){
			nx+=dx[d];
			ny+=dy[d];
			if(!vst[nx][ny]){
				ans++;
				//cout<<"("<<nx<<","<<ny<<")"<<endl;
				vst[nx][ny]=1;
			}
		}
		else{
			d=(d+1)%4;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int no=0;no<T;no++){
		ans=0;
		for(int i=0;i<1009;i++){
			for(int j=0;j<1009;j++){
				vst[i][j]=0;
				road[i][j]=0;
			}	
		}	
		cin>>m>>n>>t;
		cin>>nx>>ny>>d;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>ch;
				if(ch=='.'){
					road[i][j]=1;
				}
				else{
					road[i][j]=0;
				}
			}
		}
		if(t==1){
			nx=nx+dx[d];
			ny=ny+dy[d];
			if(road[nx][ny]){
				cout<<2<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
		else{
			solve();
		}
	}
	return 0;
}

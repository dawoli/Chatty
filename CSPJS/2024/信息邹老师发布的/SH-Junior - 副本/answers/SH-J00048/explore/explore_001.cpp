#include<bits/stdc++.h>

using namespace std;

string s[1005];
int cnt;

int main(){
	freopen("explore.in","r",sdtin);
	freopen("explore.out","w",stdout); 
	int t,n,m,k,x,y,d;
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		cnt=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		bool vis[1005][1005]={{0}};
//		d=(d+2)%4;
		while(k--){
			int x0,y0;
			if(d==0){
				x0=x;
				y0=y+1;
			} 
			else if(d==1){
				x0=x+1;
				y0=y;
			}
			else if(d==2){
				x0=x;
				y0=y-1;
			}
			else if(d==3){
				x0=x-1;
				y0=y;
			}
			if(y0<=m && y0>0 && x0<=n && x0>0 && s[x0][y0] == '.') {
				x=x0;
				y=y0;
				if(!vis[x][y]) {
					cnt++;
//					cout<<"done"<<x<<' '<<y<<endl; 
				}
				vis[x][y]=1;
				
			}
			else{
				d=(d+1)%4;
//				cout<<"NO"<<d<<endl; 
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}


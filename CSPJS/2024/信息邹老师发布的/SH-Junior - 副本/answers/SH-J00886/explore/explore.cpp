#include<bits/stdc++.h>
using namespace std;
bool mp[1010][1010];
bool r[1010][1010];
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		int n,m,k,x,y,d,cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				r[i][j]=0,mp[i][j]=0;
			}
		}
		r[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='x')mp[i][j]=1;
			}
		}
		for(int i=1;i<=k;i++){
			int x_=x,y_=y;
			if(d==0)y_++;
			if(d==1)x_++;
			if(d==2)y_--;
			if(d==3)x_--;
			if(1<=x_&&x_<=n&&1<=y_&&y_<=m){
				if(mp[x_][y_]==0){
					x=x_,y=y_;
					r[x][y]=1;
				} 
				else d++,d=d%4;
			}
			else d++,d=d%4;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(r[i][j])cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

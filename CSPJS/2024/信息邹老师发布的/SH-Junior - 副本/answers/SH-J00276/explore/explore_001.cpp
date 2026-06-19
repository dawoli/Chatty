#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int ans[5];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		bool v[1005][1005]={false};
		int n,m,k,x,y,d,s=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		v[x][y]=true;
		for(int i=0;i<k;i++){
			if(d==0){
				if(y+1<=m && a[x][y+1]=='.'){
					y++;
				}
				else{
					d++;
				}
			}
			else if(d==1){
				if(x+1<=n && a[x+1][y]=='.'){
					x++;
				}
				else{
					d++;
				}
			}
			else if(d==2){
				if(y-1>=0 && a[x][y-1]=='.'){
					y--;
				}
				else{
					d++;
				}
			}
			else if(d==3){
				if(x-1>=0 && a[x-1][y]=='.'){
					x--;
				}
				else{
					d=0;
				}
			}
			if(v[x][y]==false){
				s++;
				v[x][y]=true;
			}
		}
		ans[z]=s;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

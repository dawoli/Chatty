#include<bits/stdc++.h>
using namespace std;
int ls[1002][1002];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	int t;
	cin>>t;
	while (t--){
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for (int i=0;i<=n+1;i++){
			for (int j=0;j<=m+1;j++){
				ls[i][j]=0; 
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				char a;
				cin>>a;
				if (a=='.'){
					ls[i][j]=1;
				}
			}
		}
		set<pair<int,int>> ans;
		ans.insert({x,y});
		while (k--){
			int x1,y1;
			if (d==0){
				x1=x;
				y1=y+1;
			}
			if (d==1){
				x1=x+1;
				y1=y;
			}
			if (d==2){
				x1=x;
				y1=y-1;
			}
			if (d==3){
				x1=x-1;
				y1=y;
			}
			if (ls[x1][y1]==1){
				x=x1;
				y=y1;
				ans.insert({x,y});
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans.size()<<endl;
	}
	return 0;
} 

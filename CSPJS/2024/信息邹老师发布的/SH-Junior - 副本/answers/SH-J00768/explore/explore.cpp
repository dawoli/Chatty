#include<bits/stdc++.h>
using namespace std;
string a[1010]; 
int b[1010][1010],t;
int n,m,k,xx,yy,d,cnt=0;
void dfs(int x,int y,int k,int d){
	if(k==0){
		return;
	}
	if(d==0){
		if((y+1)<=m){
			if(a[x][y+1]=='.'){
				b[x][y+1]++;
				dfs(x,y+1,k-1,d);	
			}
		}
		else{
			dfs(x,y,k,(d+1)%4);
		}
	}
	else if(d==1){
		if((x+1)<=n){
			if(a[x+1][y]=='.'){
				b[x+1][y]++;
				dfs(x+1,y,k-1,d);
			}
		}
		else{
			dfs(x,y,k,(d+1)%4);
		}
	}
	else if(d==2){
		if((y-1)>=1){
			if(a[x][y-1]=='.'){
				b[x][y-1]++;
				dfs(x,y-1,k-1,d);	
			}
		}
		else{
			dfs(x,y,k,(d+1)%4);
		}
	}
	else if(d==3){
		if((x-1)>=1){
			if(a[x-1][y]=='.'){
				b[x-1][y]++;
				dfs(x-1,y,k-1,d);	
			}
		}
		else{
			dfs(x,y,k,(d+1)%4);
		}
	}	
		
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n>>m>>k;
		cin>>xx>>yy>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(xx,yy,k,d);
		for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(b[i][j]){
						cnt++;
					}
				}
			}
		cout<<cnt+1<<endl;
	}
	return 0;
}

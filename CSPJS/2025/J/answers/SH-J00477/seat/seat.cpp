#include<bits/stdc++.h>
using namespace std;
int n,m,grid[109],score,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>grid[i];
			score=grid[i-2];
	}
	sort(grid+1,grid+n+1);
	int grider[109][109];
	grider[1][1]=grid[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			grider[i][j]=grid[i-1];
		}
	}
	if(grider[0][0]==grid[0]){
		cout<<"1"<<" "<<"1"<<endl;
		return 0;
	}
	else if(grider[0][n-1]==grid[m]){
		cout<<"1"<<" "<<m<<endl;
		return 0;
	}
	else if(grider[1][m-1]==grid[n-1]){
		cout<<"2"<<" "<<n<<endl;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){		
				if(grider[i][j]==score){				
					x=i;
					y=j;
				}	
			}
		}
		cout<<x+1<<" "<<y+1<<endl;
	}
	return 0;
}

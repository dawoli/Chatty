#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,m,k;
char tu[1003][1003];
bool check(int x,int y,int d){
	if (d==0){
		tu[x][y++];
		if (x<=0 || x>n || y<=0 || y>m || tu[x][y]=='x'){
			return false;
		}
	}
	else if (d==1){
		tu[x++][y];
		if (x<=0 || x>n || y<=0 || y>m || tu[x][y]=='x'){
			return false;
		}
	}
	else if (d==2){
		tu[x][y--];
		if (x<=0 || x>n || y<=0 || y>m || tu[x][y]=='x'){
			return false;
		}
	}
	else if (d==3){
		tu[x--][y];
		if (x<=0 || x>n || y<=0 || y>m || tu[x][y]=='x'){
			return false;
		}
	}
	return true;
}
void move(int x,int y,int d){
	
	if (d==0){
		tu[x][y+1];
	}
	else if (d==1){
		tu[x+1][y];
	}
	else if (d==2){
		tu[x][y-1];
	}
	else if (d==3){
		tu[x-1][y];
	}
}
int main(){
	freopen ("explore.in","r",stdin);
	freopen ("explore.out","w",stdout);
	cin>>T;
	int x,y,d;
	while (T--){
		int ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>tu[i][j];
			}
		}
		tu[x][y]='l';
		for (int times=0;times<k;times++){
			if (check(x,y,d)){
				
				move(x,y,d);
				if (d==0){
					y++;
				}
				else if (d==1){
					x++;
				}
				else if (d==2){
					y--;
				}
				else if (d==3){
					x--;
				}
				tu[x][y]='l';
			}
			else {
				d=(d+1)%4;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (tu[i][j]=='l'){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

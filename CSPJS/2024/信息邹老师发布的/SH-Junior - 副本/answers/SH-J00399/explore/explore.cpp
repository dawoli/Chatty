#include<bits/stdc++.h>
using namespace std;
char e[1010][1010];
bool v[1010][1010];
short t;
short d;
int n,m;
int k;
int x,y;
bool go(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m){
		return false;
	}
	else if(e[i][j]=='x'){
		return false;
	}
	else if(e[i][j]=='.'){
		return true;
	}
}
int main(){
	freopen(explore.in,"r",stdin);
	freopen(explore.out,"w",stdout);
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		x--;
		y--;
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				e[i][j]=getchar();
			}
			getchar();
		}
		for(int i=0;i<k;i++){
			v[x][y]=true;
//			cout<<x<<' '<<y<<'\n';
			switch(d){
				case(0):
					if(go(x,y+1)){
						++y;
					}
					else{
						d=1;
					}
					break;
				case(1):
					if(go(x+1,y)){
						++x;
					}
					else{
						d=2;
					}
					break;
				case(2):
					if(go(x,y-1)){
						--y;
					}
					else{
						d=3;
					}
					break;
				case(3):
					if(go(x-1,y)){
						--x;
					}
					else{
						d=0;
					}
					break;
				default:
					d=4;
					break;
			}
//			cout<<x<<' '<<y<<'\n';
			v[x][y]=true;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(v[i][j]){
					v[i][j]=false;
					cnt++;
//					cout<<i<<' '<<j<<'\n';
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
/*

*/

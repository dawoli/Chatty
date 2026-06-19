#include<iostream>
using namespace std;
int n,ans;
bool poker[10][20];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		char a,b;
		cin>>a>>b;
		if(a=='D') {
			if(b=='A') poker[1][1]=1;
			else if(b=='T') poker[1][10]=1;
			else if(b=='J') poker[1][11]=1;
			else if(b=='Q') poker[1][12]=1;
			else if(b=='K') poker[1][13]=1;
			else poker[1][b-'0']=1;
		}
		else if(a=='C') {
			if(b=='A') poker[2][1]=1;
			else if(b=='T') poker[2][10]=1;
			else if(b=='J') poker[2][11]=1;
			else if(b=='Q') poker[2][12]=1;
			else if(b=='K') poker[2][13]=1;
			else poker[2][b-'0']=1;
		}
		else if(a=='H') {
			if(b=='A') poker[3][1]=1;
			else if(b=='T') poker[3][10]=1;
			else if(b=='J') poker[3][11]=1;
			else if(b=='Q') poker[3][12]=1;
			else if(b=='K') poker[3][13]=1;
			else poker[3][b-'0']=1;
		}
		else if(a=='S') {
			if(b=='A') poker[4][1]=1;
			else if(b=='T') poker[4][10]=1;
			else if(b=='J') poker[4][11]=1;
			else if(b=='Q') poker[4][12]=1;
			else if(b=='K') poker[4][13]=1;
			else poker[4][b-'0']=1;
		}
	}
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=13;j++) {
			if(!poker[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}

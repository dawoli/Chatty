#include<bits/stdc++.h>
using namespace std;
int c[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='D'){
			if(b=='A') c[1][1]++;
			else if(b>='2'&&b<='9') c[1][b-'0']++;//枚举所有可能 
			else if(b=='T') c[1][10]++;
			else if(b=='J') c[1][11]++;
			else if(b=='Q') c[1][12]++;
			else if(b=='K') c[1][13]++;
		}
		else if(a=='C'){
			if(b=='A') c[2][1]++;
			else if(b>='2'&&b<='9') c[2][b-'0']++;
			else if(b=='T') c[2][10]++;
			else if(b=='J') c[2][11]++;
			else if(b=='Q') c[2][12]++;
			else if(b=='K') c[2][13]++;
		}
		else if(a=='H'){
			if(b=='A') c[3][1]++;
			else if(b>='2'&&b<='9') c[3][b-'0']++;
			else if(b=='T') c[3][10]++;
			else if(b=='J') c[3][11]++;
			else if(b=='Q') c[3][12]++;
			else if(b=='K') c[3][13]++;
		}
		else if(a=='S'){
			if(b=='A') c[4][1]++;
			else if(b>='2'&&b<='9') c[4][b-'0']++;
			else if(b=='T') c[4][10]++;
			else if(b=='J') c[4][11]++;
			else if(b=='Q') c[4][12]++;
			else if(b=='K') c[4][13]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(c[i][j]==0) cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
int n,ans,m[5][15];
char a,b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	  cin>>a>>b;
	  int x=0,y=0;
	  if(a=='D') x=1;
	  else if(a=='C') x=2;
	  else if(a=='H') x=3;
	  else if(a=='S') x=4;
	  if(b>='2'&&b<='9') y=b-'0';
	  else if(b=='A') y=1;
	  else if(b=='T') y=10;
	  else if(b=='J') y=11;
	  else if(b=='Q') y=12;
	  else if(b=='K') y=13;
	  m[x][y]++;
	}
	for(int i=1;i<=4;i++){
	  for(int j=1;j<=13;j++){
	  	if(m[i][j]>0) ans++;
	  }
	}
	cout<<52-ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int f[9][29];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		int x=0,y=0;
		if(s[0]=='D') x=1;
		else if(s[0]=='C') x=2;
		else if(s[0]=='H') x=3;
		else x=4;
		if(s[1]=='A') y=1;
		else if(s[1]=='T') y=10;
		else if(s[1]=='J') y=11;
		else if(s[1]=='Q') y=12;
		else if(s[1]=='K') y=13;
		else y=s[1]-'0';
		f[x][y]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(f[i][j]==0) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

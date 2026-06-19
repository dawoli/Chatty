#include<bits/stdc++.h>
using namespace std;
bool a[5][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		//cout<<s;
		int x,y;
		if(s[0]=='D') x=0;
		else if(s[0]=='C') x=1;
		else if(s[0]=='H') x=2;
		else x=3;
		//cout<<x;
		if(s[1]=='A') y=0;
		else if(s[1]=='2') y=1;
		else if(s[1]=='3') y=2;
		else if(s[1]=='4') y=3;
		else if(s[1]=='5') y=4;
		else if(s[1]=='6') y=5;
		else if(s[1]=='7') y=6;
		else if(s[1]=='8') y=7;
		else if(s[1]=='9') y=8;
		else if(s[1]=='T') y=9;
		else if(s[1]=='J') y=10;
		else if(s[1]=='Q') y=11;
		else y=12;
		
		a[x][y]=true;
	}
	int ans=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(a[i][j]==false){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
D=fangpian
C=caohua
H=hongtao
S=heitao

*/ 

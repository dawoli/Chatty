#include<bits/stdc++.h>//ШЅжи 
using namespace std;
bool m[6][15]; //D1 C2 H3 S4
long long n,cnt=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]=='D'&&s[1]=='A') m[1][1]=1;//D
		else if(s[0]=='D'&&s[1]=='2') m[1][2]=1;
		else if(s[0]=='D'&&s[1]=='3') m[1][3]=1;
		else if(s[0]=='D'&&s[1]=='4') m[1][4]=1;
		else if(s[0]=='D'&&s[1]=='5') m[1][5]=1;
		else if(s[0]=='D'&&s[1]=='6') m[1][6]=1;
		else if(s[0]=='D'&&s[1]=='7') m[1][7]=1;
		else if(s[0]=='D'&&s[1]=='8') m[1][8]=1;
		else if(s[0]=='D'&&s[1]=='9') m[1][9]=1;
		else if(s[0]=='D'&&s[1]=='T') m[1][10]=1;
		else if(s[0]=='D'&&s[1]=='J') m[1][11]=1;
		else if(s[0]=='D'&&s[1]=='Q') m[1][12]=1;
		else if(s[0]=='D'&&s[1]=='K') m[1][13]=1;
		else if(s[0]=='C'&&s[1]=='A') m[2][1]=1;//C
		else if(s[0]=='C'&&s[1]=='2') m[2][2]=1;
		else if(s[0]=='C'&&s[1]=='3') m[2][3]=1;
		else if(s[0]=='C'&&s[1]=='4') m[2][4]=1;
		else if(s[0]=='C'&&s[1]=='5') m[2][5]=1;
		else if(s[0]=='C'&&s[1]=='6') m[2][6]=1;
		else if(s[0]=='C'&&s[1]=='7') m[2][7]=1;
		else if(s[0]=='C'&&s[1]=='8') m[2][8]=1;
		else if(s[0]=='C'&&s[1]=='9') m[2][9]=1;
		else if(s[0]=='C'&&s[1]=='T') m[2][10]=1;
		else if(s[0]=='C'&&s[1]=='J') m[2][11]=1;
		else if(s[0]=='C'&&s[1]=='Q') m[2][12]=1;
		else if(s[0]=='C'&&s[1]=='K') m[2][13]=1;
		else if(s[0]=='H'&&s[1]=='A') m[3][1]=1;//H
		else if(s[0]=='H'&&s[1]=='2') m[3][2]=1;
		else if(s[0]=='H'&&s[1]=='3') m[3][3]=1;
		else if(s[0]=='H'&&s[1]=='4') m[3][4]=1;
		else if(s[0]=='H'&&s[1]=='5') m[3][5]=1;
		else if(s[0]=='H'&&s[1]=='6') m[3][6]=1;
		else if(s[0]=='H'&&s[1]=='7') m[3][7]=1;
		else if(s[0]=='H'&&s[1]=='8') m[3][8]=1;
		else if(s[0]=='H'&&s[1]=='9') m[3][9]=1;
		else if(s[0]=='H'&&s[1]=='T') m[3][10]=1;
		else if(s[0]=='H'&&s[1]=='J') m[3][11]=1;
		else if(s[0]=='H'&&s[1]=='Q') m[3][12]=1;
		else if(s[0]=='H'&&s[1]=='K') m[3][13]=1;
		else if(s[0]=='S'&&s[1]=='A') m[4][1]=1;//S
		else if(s[0]=='S'&&s[1]=='2') m[4][2]=1;
		else if(s[0]=='S'&&s[1]=='3') m[4][3]=1;
		else if(s[0]=='S'&&s[1]=='4') m[4][4]=1;
		else if(s[0]=='S'&&s[1]=='5') m[4][5]=1;
		else if(s[0]=='S'&&s[1]=='6') m[4][6]=1;
		else if(s[0]=='S'&&s[1]=='7') m[4][7]=1;
		else if(s[0]=='S'&&s[1]=='8') m[4][8]=1;
		else if(s[0]=='S'&&s[1]=='9') m[4][9]=1;
		else if(s[0]=='S'&&s[1]=='T') m[4][10]=1;
		else if(s[0]=='S'&&s[1]=='J') m[4][11]=1;
		else if(s[0]=='S'&&s[1]=='Q') m[4][12]=1;
		else if(s[0]=='S'&&s[1]=='K') m[4][13]=1;
	}for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(m[i][j]==0){
				cnt++;
			}
		}
	}cout<<cnt;
}
/*4
DQ
H3
DQ
DT*/

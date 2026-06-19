#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool p[15][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]=='D'){
			if(s[1]=='A')p[1][1]=true;
			else if(s[1]=='2')p[1][2]=true;
			else if(s[1]=='3')p[1][3]=true;
			else if(s[1]=='4')p[1][4]=true;
			else if(s[1]=='5')p[1][5]=true;
			else if(s[1]=='6')p[1][6]=true;
			else if(s[1]=='7')p[1][7]=true;
			else if(s[1]=='8')p[1][8]=true;
			else if(s[1]=='9')p[1][9]=true;
			else if(s[1]=='T')p[1][10]=true;
			else if(s[1]=='J')p[1][11]=true;
			else if(s[1]=='Q')p[1][12]=true;
			else if(s[1]=='K')p[1][13]=true;
		}
		else if(s[0]=='C'){
			if(s[1]=='A')p[2][1]=true;
			else if(s[1]=='2')p[2][2]=true;
			else if(s[1]=='3')p[2][3]=true;
			else if(s[1]=='4')p[2][4]=true;
			else if(s[1]=='5')p[2][5]=true;
			else if(s[1]=='6')p[2][6]=true;
			else if(s[1]=='7')p[2][7]=true;
			else if(s[1]=='8')p[2][8]=true;
			else if(s[1]=='9')p[2][9]=true;
			else if(s[1]=='T')p[2][10]=true;
			else if(s[1]=='J')p[2][11]=true;
			else if(s[1]=='Q')p[2][12]=true;
			else if(s[1]=='K')p[2][13]=true;
		}
		else if(s[0]=='H'){
			if(s[1]=='A')p[3][1]=true;
			else if(s[1]=='2')p[3][2]=true;
			else if(s[1]=='3')p[3][3]=true;
			else if(s[1]=='4')p[3][4]=true;
			else if(s[1]=='5')p[3][5]=true;
			else if(s[1]=='6')p[3][6]=true;
			else if(s[1]=='7')p[3][7]=true;
			else if(s[1]=='8')p[3][8]=true;
			else if(s[1]=='9')p[3][9]=true;
			else if(s[1]=='T')p[3][10]=true;
			else if(s[1]=='J')p[3][11]=true;
			else if(s[1]=='Q')p[3][12]=true;
			else if(s[1]=='K')p[3][13]=true;
		}
		else if(s[0]=='S'){
			if(s[1]=='A')p[4][1]=true;
			else if(s[1]=='2')p[4][2]=true;
			else if(s[1]=='3')p[4][3]=true;
			else if(s[1]=='4')p[4][4]=true;
			else if(s[1]=='5')p[4][5]=true;
			else if(s[1]=='6')p[4][6]=true;
			else if(s[1]=='7')p[4][7]=true;
			else if(s[1]=='8')p[4][8]=true;
			else if(s[1]=='9')p[4][9]=true;
			else if(s[1]=='T')p[4][10]=true;
			else if(s[1]=='J')p[4][11]=true;
			else if(s[1]=='Q')p[4][12]=true;
			else if(s[1]=='K')p[4][13]=true;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!p[i][j])ans++;
		}
	}
	cout<<ans;
	return 0;
}

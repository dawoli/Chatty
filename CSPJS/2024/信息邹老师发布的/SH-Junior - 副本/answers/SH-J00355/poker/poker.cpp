#include<bits\stdc++.h>
using namespace std;
bool pkc[10][20];
int n;
string qxp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=1;i<=4;i++)
	for(int j=1;j<=13;j++)
		pkc[i][j]=0;
	cin>>n;
	while(n--){
		cin>>qxp;
		int tx,ty;
		if(qxp[0]=='D')tx=1;
		else if(qxp[0]=='C')tx=2;
		else if(qxp[0]=='H')tx=3;
		else if(qxp[0]=='S')tx=4;
		if(qxp[1]=='A')ty=1;
		else if(qxp[1]=='T')ty=10;
		else if(qxp[1]=='J')ty=11;
		else if(qxp[1]=='Q')ty=12;
		else if(qxp[1]=='K')ty=13;
		else ty=qxp[1]-'0';
		pkc[tx][ty]=1;
	}
	int ans=52;
	for(int i=1;i<=4;i++)
	for(int j=1;j<=13;j++){
		if(pkc[i][j])ans--;
	}
	cout<<ans;
	return 0;
} 

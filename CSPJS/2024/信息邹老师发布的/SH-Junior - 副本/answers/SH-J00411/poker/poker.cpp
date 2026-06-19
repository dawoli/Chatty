#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
char hs,ds;
bool a[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>hs>>ds;
		if(hs=='D'){
			if(ds=='A') a[1][1]=true;
			else if(ds=='2') a[1][2]=true;
			else if(ds=='3') a[1][3]=true;
			else if(ds=='4') a[1][4]=true;
			else if(ds=='5') a[1][5]=true;
			else if(ds=='6') a[1][6]=true;
			else if(ds=='7') a[1][7]=true;
			else if(ds=='8') a[1][8]=true;
			else if(ds=='9') a[1][9]=true;
			else if(ds=='T') a[1][10]=true;
			else if(ds=='J') a[1][11]=true;
			else if(ds=='Q') a[1][12]=true;
			else if(ds=='K') a[1][13]=true;
		}
		else if(hs=='C'){
			if(ds=='A') a[2][1]=true;
			else if(ds=='2') a[2][2]=true;
			else if(ds=='3') a[2][3]=true;
			else if(ds=='4') a[2][4]=true;
			else if(ds=='5') a[2][5]=true;
			else if(ds=='6') a[2][6]=true;
			else if(ds=='7') a[2][7]=true;
			else if(ds=='8') a[2][8]=true;
			else if(ds=='9') a[2][9]=true;
			else if(ds=='T') a[2][10]=true;
			else if(ds=='J') a[2][11]=true;
			else if(ds=='Q') a[2][12]=true;
			else if(ds=='K') a[2][13]=true;
		}
		else if(hs=='H'){
			if(ds=='A') a[3][1]=true;
			else if(ds=='2') a[3][2]=true;
			else if(ds=='3') a[3][3]=true;
			else if(ds=='4') a[3][4]=true;
			else if(ds=='5') a[3][5]=true;
			else if(ds=='6') a[3][6]=true;
			else if(ds=='7') a[3][7]=true;
			else if(ds=='8') a[3][8]=true;
			else if(ds=='9') a[3][9]=true;
			else if(ds=='T') a[3][10]=true;
			else if(ds=='J') a[3][11]=true;
			else if(ds=='Q') a[3][12]=true;
			else if(ds=='K') a[3][13]=true;
		}
		else if(hs=='S'){
			if(ds=='A') a[4][1]=true;
			else if(ds=='2') a[4][2]=true;
			else if(ds=='3') a[4][3]=true;
			else if(ds=='4') a[4][4]=true;
			else if(ds=='5') a[4][5]=true;
			else if(ds=='6') a[4][6]=true;
			else if(ds=='7') a[4][7]=true;
			else if(ds=='8') a[4][8]=true;
			else if(ds=='9') a[4][9]=true;
			else if(ds=='T') a[4][10]=true;
			else if(ds=='J') a[4][11]=true;
			else if(ds=='Q') a[4][12]=true;
			else if(ds=='K') a[4][13]=true;
		}	
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++)
		if(a[i][j]) ans--;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool b[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char c,m;
		cin>>c>>m;
		if(c=='D'){
			if(m=='A') b[0][0]=1;
			if(m=='2') b[0][1]=1;
			if(m=='3') b[0][2]=1;
			if(m=='4') b[0][3]=1;
			if(m=='5') b[0][4]=1;
			if(m=='6') b[0][5]=1;
			if(m=='7') b[0][6]=1;
			if(m=='8') b[0][7]=1;
			if(m=='9') b[0][8]=1;
			if(m=='T') b[0][9]=1;
			if(m=='J') b[0][10]=1;
			if(m=='Q') b[0][11]=1;
			if(m=='K') b[0][12]=1;
		}else if(c=='C'){
			if(m=='A') b[1][0]=1;
			if(m=='2') b[1][1]=1;
			if(m=='3') b[1][2]=1;
			if(m=='4') b[1][3]=1;
			if(m=='5') b[1][4]=1;
			if(m=='6') b[1][5]=1;
			if(m=='7') b[1][6]=1;
			if(m=='8') b[1][7]=1;
			if(m=='9') b[1][8]=1;
			if(m=='T') b[1][9]=1;
			if(m=='J') b[1][10]=1;
			if(m=='Q') b[1][11]=1;
			if(m=='K') b[1][12]=1;
		}else if(c=='H'){
			if(m=='A') b[2][0]=1;
			if(m=='2') b[2][1]=1;
			if(m=='3') b[2][2]=1;
			if(m=='4') b[2][3]=1;
			if(m=='5') b[2][4]=1;
			if(m=='6') b[2][5]=1;
			if(m=='7') b[2][6]=1;
			if(m=='8') b[2][7]=1;
			if(m=='9') b[2][8]=1;
			if(m=='T') b[2][9]=1;
			if(m=='J') b[2][10]=1;
			if(m=='Q') b[2][11]=1;
			if(m=='K') b[2][12]=1;
		}else if(c=='S'){
			if(m=='A') b[3][0]=1;
			if(m=='2') b[3][1]=1;
			if(m=='3') b[3][2]=1;
			if(m=='4') b[3][3]=1;
			if(m=='5') b[3][4]=1;
			if(m=='6') b[3][5]=1;
			if(m=='7') b[3][6]=1;
			if(m=='8') b[3][7]=1;
			if(m=='9') b[3][8]=1;
			if(m=='T') b[3][9]=1;
			if(m=='J') b[3][10]=1;
			if(m=='Q') b[3][11]=1;
			if(m=='K') b[3][12]=1;
		}
	}
	int sum=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(b[i][j]) sum++;
		}
	}
	sum=52-sum; 
	cout<<sum;
	return 0;
}

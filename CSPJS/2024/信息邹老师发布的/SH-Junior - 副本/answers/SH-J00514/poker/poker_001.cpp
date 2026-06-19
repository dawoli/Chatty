#include <bits/stdc++.h>
using namespace std;
int n,rec,p[5][14],a,b;
char c[2];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	a=0;b=0;rec=0;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		cin >> c;
		if(c[0]=='D') a=1;
		else if(c[0]=='C') a=2;
		else if(c[0]=='H') a=3;
		else if(c[0]=='S') a=4;
		if(c[1]=='A') b=1;
		else if(c[1]=='2') b=2;
		else if(c[1]=='3') b=3;
		else if(c[1]=='4') b=4;
		else if(c[1]=='5') b=5;
		else if(c[1]=='6') b=6;
		else if(c[1]=='7') b=7;
		else if(c[1]=='8') b=8;
		else if(c[1]=='9') b=9;
		else if(c[1]=='T') b=10;
		else if(c[1]=='J') b=11;
		else if(c[1]=='Q') b=12;
		else if(c[1]=='K') b=13;
		p[a][b]++;
	}
	for(int i=1;i<=4;i++) for(int j=1;j<=13;j++)
		if(p[i][j]!=0) rec++;
	cout << 52-rec;
	return 0;
}

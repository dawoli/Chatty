#include<bits/stdc++.h>
using namespace std;
int cnt,a[5][15];
char b[3][60];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[1][i]>>b[2][i];
	}
	for(int i=1;i<=n;i++){
		int x,y;
		if(b[1][i]=='D')x=1;
		else if(b[1][i]=='C')x=2;
		else if(b[1][i]=='H')x=3;
		else if(b[1][i]=='S')x=4;
		
		if(b[2][i]=='A')y=1;
		else if(b[2][i]=='2')y=2;
		else if(b[2][i]=='3')y=3;
		else if(b[2][i]=='4')y=4;
		else if(b[2][i]=='5')y=5;
		else if(b[2][i]=='6')y=6;
		else if(b[2][i]=='7')y=7;
		else if(b[2][i]=='8')y=8;
		else if(b[2][i]=='9')y=9;
		else if(b[2][i]=='T')y=10;
		else if(b[2][i]=='J')y=11;
		else if(b[2][i]=='Q')y=12;
		else if(b[2][i]=='K')y=13;
		a[x][y]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==0)cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

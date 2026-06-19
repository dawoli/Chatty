#include<bits/stdc++.h>
using namespace std;
int n,c[10][60];
char a,b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='H')	x=1;
		else if(a=='D')	x=2;
		else if(a=='S')	x=3;
		else if(a=='C')	x=4;
		if(b=='A')	y=1;
		else if('2'<=b&&b<='9')	y=b-'0';
		else if(b=='T')	y=10;
		else if(b=='J')	y=11;
		else if(b=='Q')	y=12;
		else if(b=='K')	y=13;
		c[x][y]++;
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(c[i][j]==0)
				cnt++;
	cout<<cnt<<"\n";
	return 0;
}

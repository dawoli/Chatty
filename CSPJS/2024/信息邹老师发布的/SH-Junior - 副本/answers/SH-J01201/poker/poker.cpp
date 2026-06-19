#include <iostream>
#include <cstdio>
using namespace std;

bool poker[13][4];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c[3];
		cin>>c[1]>>c[2];
		int a,b;
		if(c[2]=='A') b=1;
		if(c[2]=='2') b=2;
		if(c[2]=='3') b=3;
		if(c[2]=='4') b=4;
		if(c[2]=='5') b=5;
		if(c[2]=='6') b=6;
		if(c[2]=='7') b=7;
		if(c[2]=='8') b=8;
		if(c[2]=='9') b=9;
		if(c[2]=='T') b=10;
		if(c[2]=='J') b=11;
		if(c[2]=='Q') b=12;
		if(c[2]=='K') b=13;
		if(c[1]=='D') a=1;
		if(c[1]=='C') a=2;
		if(c[1]=='H') a=3;
		if(c[1]=='S') a=4;
		poker[b][a]=1;
	}
	
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(poker[i][j]==0) cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
}

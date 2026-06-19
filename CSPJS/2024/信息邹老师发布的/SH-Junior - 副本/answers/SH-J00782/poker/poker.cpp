#include<iostream>
#include<stdio.h>
using namespace std;
bool c[5][20];
int n;
int x,y;
char a,b;
int cnt=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='D') x=1;
		else if(a=='C') x=2;
		else if(a=='H') x=3;
		else x=4;
		if(b>='2'&&b<='9') y=b-'0';
		else if(b=='A') y=1;
		else if(b=='T') y=10;
		else if(b=='J') y=11;
		else if(b=='Q') y=12;
		else y=13;
		if(!c[x][y]){
			c[x][y]=1;
			cnt--;
		}
	}
	cout<<cnt<<endl;
    return 0;
}

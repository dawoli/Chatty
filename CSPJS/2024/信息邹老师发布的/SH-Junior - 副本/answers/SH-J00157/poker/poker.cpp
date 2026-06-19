#include<bits/stdc++.h>
using namespace std;
bool po[4][15];
int idx[4];
int n;
int check(char c){
	if(c=='D') return 0;
	if(c=='C') return 1;
	if(c=='H') return 2;
	if(c=='S') return 3;
}
int che(char c){
	if(c>='2'&&c<='9') return c-'0';
	else if(c=='A') return 1;
	else if(c=='T') return 10;
	else if(c=='J') return 11;
	else if(c=='Q') return 12;
	else if(c=='K') return 13;

}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c[3];
		cin>>c;
		po[check(c[0])][che(c[1])]=true;
	}
	int cnt=0;
	for(int i=0;i<4;i++){
		for(int j=1;j<=13;j++){
			if(!po[i][j]) cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}


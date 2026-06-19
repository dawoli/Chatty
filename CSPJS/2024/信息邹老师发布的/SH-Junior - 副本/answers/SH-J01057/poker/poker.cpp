#include<bits/stdc++.h>
using namespace std;
int n,x,y,f=52,b[6][16];
struct P{
	char a,b;
} s[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>s[i].a>>s[i].b;
	for(int i=1;i<=n;++i){
		if(s[i].a=='D') x=1;
		if(s[i].a=='C') x=2;
		if(s[i].a=='H') x=3;
		if(s[i].a=='S') x=4;
		if(s[i].b=='A') y=1;
		if('0'<=s[i].b&&s[i].b<='9') y=s[i].b-'0';
		if(s[i].b=='T') y=10;
		if(s[i].b=='J') y=11;
		if(s[i].b=='Q') y=12;
		if(s[i].b=='K') y=13;
		b[x][y]=1;
	}
	for(int i=1;i<=5;++i){
		for(int j=1;j<=15;++j){
			if(b[i][j]==1) f--;
		}
	}
    cout<<f;
	return 0;
}

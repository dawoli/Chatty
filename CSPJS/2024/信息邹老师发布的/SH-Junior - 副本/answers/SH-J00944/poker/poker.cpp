#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
bool c[8][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=1;i<=4;++i){
		for(int j=1;j<=13;++j){
			c[i][j]=false;
		}
	}
	cin>>n;
	for(int i=1;i<=n;++i){
		char x,y;
		int a,b;
		cin>>x>>y;
		if(x=='D')
			a=1;
		if(x=='C')
			a=2;
		if(x=='H')
			a=3;
		if(x=='S')
			a=4;
		b=y-'1'+1;
		if(y=='T')
			b=10;
		if(y=='J')
			b=11;
		if(y=='Q')
			b=12;
		if(y=='K')
			b=13;
		if(y=='A')
			b=1;
		c[a][b]=true;
	}
	for(int i=1;i<=4;++i){
		for(int j=1;j<=13;++j){
			if(c[i][j]==false){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool st[7][29];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int ans=52;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int x,y;
		if(a=='D')x=1;
		else if(a=='H')x=2;
		else if(a=='S')x=3;
		else x=4;
		if(b>='1'&&b<='9')y=b-'0';
		else if(b=='A')y=1;
		else if(b=='T')y=10;
		else if(b=='J')y=11;
		else if(b=='Q')y=12;
		else y=13;
		st[x][y]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(st[i][j]==1)ans--;
		}
	}
	cout<<ans;
	return 0;
}

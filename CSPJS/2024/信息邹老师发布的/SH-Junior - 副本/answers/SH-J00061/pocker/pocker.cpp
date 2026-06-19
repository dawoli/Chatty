#include<bits/stdc++.h>
using namespace std;
bool a[5][14];
int main(){
	freopen("pocker.in","r",stdin);
	freopen("pocker.out","w",stdout);
	int n;
	cin>>n;
	int x,y;
	string z;
	for(int i=1;i<=n;i++){
		cin>>z;
		if(z[0]=='S') x=1;
		else if(z[0]=='C') x=2;
		else if(z[0]=='D') x=3;
		else if(z[0]=='H') x=4;
		
		if(z[1]=='A') y=1;
		else if(z[1]=='2') y=2;
		else if(z[1]=='3') y=3;
		else if(z[1]=='4') y=4;
		else if(z[1]=='5') y=5;
		else if(z[1]=='6') y=6;
		else if(z[1]=='7') y=7;
		else if(z[1]=='8') y=8;
		else if(z[1]=='9') y=9;
		else if(z[1]=='T') y=10;
		else if(z[1]=='J') y=11;
		else if(z[1]=='Q') y=12;
		else if(z[1]=='K') y=13;
		a[x][y]=true;
	}
	int ans=0;
	for (int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!a[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool pkr[20][10];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	char a,b;
	for(int i=1,c,d;i<=n;i++){
		cin>>a>>b;
		if(a=='D') c=0;
		else if(a=='C') c=1;
		else if(a=='H') c=2;
		else c=3;
		if(b=='A') d=1;
		else if(b=='T') d=10;
		else if(b=='J') d=11;
		else if(b=='Q') d=12;
		else if(b=='K') d=13;
		else d=b-'0';
		pkr[d][c]=1;
	}
	for(int i=1;i<=13;i++){
		for(int j=0;j<4;j++){
			if(!pkr[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}

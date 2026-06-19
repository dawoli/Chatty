#include<bits/stdc++.h>
using namespace std;
int p[10][20],n,ans;
char x,y;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		int j;
		if(x=='D') j=1;
		if(x=='C') j=2;
		if(x=='H') j=3;
		if(x=='S') j=4;
		int k;
		if(y=='A') k=1;
		else if(y=='T') k=10;
		else if(y=='J') k=11;
		else if(y=='Q') k=12;
		else if(y=='K') k=13;
		else k=y-'0';
		p[j][k]++;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(p[i][j]==0) ans++;
	cout<<ans;
	return 0;
}

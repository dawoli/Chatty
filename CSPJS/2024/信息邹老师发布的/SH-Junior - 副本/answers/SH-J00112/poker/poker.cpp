#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,c[5][20];
	cin>>n;
	char a,b;
	memset(c,0,sizeof(c));
	for(long long i=1;i<=n;i++){
		cin>>a>>b;
		long long A=0,B=0;
		if(a=='D') A=1;
		else if(a=='C') A=2;
		else if(a=='H') A=3;
		else if(a=='S') A=4;
		if(b=='A') B=1;
		else if(b>='2'&&b<='9') B=b-'0';
		else if(b=='T') B=10;
		else if(b=='J') B=11;
		else if(b=='Q') B=12;
		else if(b=='K') B=13;
		c[A][B]++;
	}
	long long ans=0;
	for(long long i=1;i<=4;i++){
		for(long long j=1;j<=13;j++){
			if(c[i][j]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
}

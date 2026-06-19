#include<bits/stdc++.h>
using namespace std;
int k[10][20],ans,n;
char s,c;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s>>c;
		int a,b;
		if(s=='D') a=1;
		if(s=='C') a=2;
		if(s=='H') a=3;
		if(s=='S') a=4;
		
		if(c=='A') b=1;
		else if(c=='T') b=10;
		else if(c=='J') b=11;
		else if(c=='Q') b=12;
		else if(c=='K') b=13;
		else b=(int)(c-'0');
		k[a][b]=1;
	}
	for(int i=1;i<=4;++i){
		for(int j=1;j<=13;++j){
			ans+=!k[i][j];
		}
	}
	cout<<ans;
	return 0;
}

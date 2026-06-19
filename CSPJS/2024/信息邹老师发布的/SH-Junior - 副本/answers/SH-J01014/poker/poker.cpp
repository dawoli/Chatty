#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool p[9][19];
char h[59],s[59];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i]>>s[i];
		int a,b;
		if(h[i]=='D') a=1;
		else if(h[i]=='C') a=2;
		else if(h[i]=='H') a=3;
		else a=4;
		if(s[i]=='A') b=1;
		else if(s[i]=='T') b=10;
		else if(s[i]=='J') b=11;
		else if(s[i]=='Q') b=12;
		else if(s[i]=='K') b=13;
		else b=s[i]-'0';
		p[a][b]=true;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(p[i][j]==false)
				ans++;
	cout<<ans;
	return 0;
}

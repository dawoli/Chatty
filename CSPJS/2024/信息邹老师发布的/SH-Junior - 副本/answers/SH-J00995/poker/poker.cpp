#include<bits/stdc++.h>
using namespace std;
int a[15][4];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		int x,y;
		if(t[0]=='D') x=0;
		else if(t[0]=='C') x=1;
		else if(t[0]=='H') x=2;
		else x=3;
		if(t[1]=='A') y=1;
		else if(t[1]=='T') y=10;
		else if(t[1]=='J') y=11;
		else if(t[1]=='Q') y=12;
		else if(t[1]=='K') y=13;
		else y=t[1]-'0';
		a[y][x]=1;
	}
	int ans=0;
	for(int i=1;i<=13;i++){
		for(int j=0;j<=3;j++){
			if(a[i][j]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
}

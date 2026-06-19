#include<bits/stdc++.h>
using namespace std;
int cnt[7][20],n;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		int u=0,h=0;
		if(s[0]=='D') u=1;
		else if(s[0]=='C') u=2;
		else if(s[0]=='H') u=3;
		else u=4;
		if(s[1]=='A') h=1;
		else if(s[1]=='T') h=10;
		else if(s[1]=='J') h=11;
		else if(s[1]=='Q') h=12;
		else if(s[1]=='K') h=13;
		else {
			h=s[1]-'0';
		}
		cnt[u][h]++;
 	}
 	int ans=0;
 	for(int i=1;i<=4;i++) {
 		for(int j=1;j<=13;j++) {
 			if(cnt[i][j]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
}

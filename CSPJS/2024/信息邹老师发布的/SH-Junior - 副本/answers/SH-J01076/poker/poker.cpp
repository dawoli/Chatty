#include<bits/stdc++.h>
using namespace std;
int n,a[10][20],cnt;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) {
		char ch[5];
		int x,y;
		cin>>ch;
		if(ch[0]=='D') x=1;
		else if(ch[0]=='C') x=2;
		else if(ch[0]=='H') x=3;
		else if(ch[0]=='S') x=4;
		if(ch[1]>='2'&&ch[1]<='9') y=ch[1]-'0';
		else if(ch[1]=='A') y=1;
		else if(ch[1]=='T') y=10;
		else if(ch[1]=='J') y=11;
		else if(ch[1]=='Q') y=12;
		else if(ch[1]=='K') y=13;
		if(a[x][y]==0) {
			a[x][y]=1;
			cnt++;
		}
	}
	cout<<52-cnt<<"\n";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool book[5][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		string p;
		int h,d;
		cin>>p;
		if (p[0]=='D') h=1;
		else if (p[0]=='C') h=2;
		else if (p[0]=='H') h=3;
		else h=4;
		if (p[1]=='A') d=1;
		else if (p[1]>='2'&&p[1]<='9') d=p[1]-48;
		else if (p[1]=='T') d=10;
		else if (p[1]=='J') d=11;
		else if (p[1]=='Q') d=12;
		else d=13;
		book[h][d]=true;
	}
	for (int i=1;i<=4;i++)
		for (int j=1;j<=13;j++)
			if (!book[i][j]) cnt++;
	cout<<cnt;
	return 0;
} 

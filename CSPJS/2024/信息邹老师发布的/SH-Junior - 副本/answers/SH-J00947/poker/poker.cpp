#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e2+10;

int n;
string st;
bool f[10][100]={};

int calc(char ch) {
	if(ch>='2' && ch<='9') {
		return ch-'0';
	}
	else if(ch=='T')
		return 10;
	else if(ch=='J')
		return 11;
	else if(ch=='Q')
		return 12;
	else if(ch=='K')
		return 13;
	else if(ch=='A')
		return 1;
}

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>st;
		int tmp=calc(st[1]);
		if(st[0]=='D') {
			f[1][tmp]=true;
		}
		else if(st[0]=='C') {
			f[2][tmp]=true;
		}
		else if(st[0]=='H') {
			f[3][tmp]=true;
		}
		else if(st[0]=='S') {
			f[4][tmp]=true;
		}
	}
	int ljy=0;
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=13;j++) {
			if(!f[i][j]) {
				ljy++;
			}
		}
	}
	cout<<ljy<<endl;
	return 0;
}

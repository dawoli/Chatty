#include<bits/stdc++.h>
using namespace std;

bool poke[5][14];
char a, b;
int n, c, d, ans=0;
string s;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	memset(poke, 0, sizeof(poke));
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		a=s[0];
		b=s[1];
		switch(a) {
			case 'D':c=1;break;
			case 'C':c=2;break;
			case 'H':c=3;break;
			case 'S':c=4;break;
		}
		switch(b) {
			case 'A':d=1;break;
			case 'T':d=10;break;
			case 'J':d=11;break;
			case 'Q':d=12;break;
			case 'K':d=13;break;
			default:d=b-'0';break;
		}
		poke[c][d]=true;
	}
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=13;j++) {
			if(!poke[i][j]) ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

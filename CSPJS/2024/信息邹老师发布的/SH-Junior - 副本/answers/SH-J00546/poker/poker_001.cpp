//ÑÕÉ«:DCHS
//Êý×Ö:A23456789TJQK
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
bool have[20][20];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		char col,num;
		cin>>col>>num;
		int a=0,b=0;
		if(col=='D')  a=1;
		if(col=='C')  a=2;
		if(col=='H')  a=3;
		if(col=='S')  a=4;
		b=num-'0';
		if(num=='A')  b=1;
		if(num=='T')  b=10;
		if(num=='J')  b=11;
		if(num=='Q')  b=12;
		if(num=='K')  b=13;
		have[a][b]=true;
	}
	int cnt=0;
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=13;j++) {
			if(!have[i][j])  cnt++;
		}
	}
	cout<<cnt;
	return 0;
}


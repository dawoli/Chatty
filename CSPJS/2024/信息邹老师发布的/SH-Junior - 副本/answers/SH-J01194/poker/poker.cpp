#include<bits/stdc++.h>
using namespace std;
bool flag[10][40];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;int a,b;
		cin>>s;
		if(s[0]=='D') a=1;
		else if(s[0]=='C') a=2;
		else if(s[0]=='H') a=3;
		else a=4;
		a=a;
		if(s[1]=='A') b=1;
		else if(s[1]=='T') b=10;
		else if(s[1]=='J') b=11;
		else if(s[1]=='Q') b=12;
		else if(s[1]=='K') b=13;
		else b=s[1]-'0';
		b=b;
		
		if(!flag[a][b]) flag[a][b]=1,cnt++;
	}
	cout<<52-cnt;
} 
/*

52


DA

CA

HA

SA

D2

C2

H2

S2

D3

C3

H3

S3

D4

C4

H4

S4

D5

C5

H5

S5

D6

C6

H6

S6

D7

C7

H7

S7

D8

C8

H8

S8

D9

C9

H9

S9

DT


CT

HT

ST

DJ

CJ

HJ

SJ

DQ

CQ

HQ

SQ

DK

CK

HK

SK






*/

#include<bits/stdc++.h>
using namespace std;
int a[7][20]={0};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int p=0,q=0;
		cin>>s;
		if(s[0]=='D') p=1;
		if(s[0]=='C') p=2;
		if(s[0]=='H') p=3;
		if(s[0]=='S') p=4;
		if(s[1]=='2') q=2;
		if(s[1]=='3') q=3;
		if(s[1]=='4') q=4;
		if(s[1]=='5') q=5;
		if(s[1]=='6') q=6;
		if(s[1]=='7') q=7;
		if(s[1]=='8') q=8;
		if(s[1]=='9') q=9;
		if(s[1]=='A') q=1;
		if(s[1]=='T') q=10;
		if(s[1]=='J') q=11;
		if(s[1]=='K') q=13;
		if(s[1]=='Q') q=12;
		a[p][q]=1;
	}
	int cnt=0;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=18;j++){
			if(a[i][j]==1) cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}

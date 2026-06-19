#include<bits/stdc++.h>
using namespace std;
int a[20][6],cnt;
int x,y,n;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(2<=s[1]-'0'&&s[1]-'0'<=9){
			x=s[1]-'0';
		}
		else if(s[1]=='A'){
			x=1;
		}
		else if(s[1]=='T') x=10;
		else if(s[1]=='J') x=11;
		else if(s[1]=='Q') x=12;
		else if(s[1]=='K') x=13;
		if(s[0]=='D') y=1;
		if(s[0]=='C') y=2;
		if(s[0]=='H') y=3;
		if(s[0]=='S') y=4;
		a[x][y]=1;
//		cout<<x<<" "<<y<<endl;
	}
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]==1) cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}

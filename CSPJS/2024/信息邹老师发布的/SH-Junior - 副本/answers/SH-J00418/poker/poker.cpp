#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
bool p[5][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int k=0,j=0;
		if(s[0]=='D') k=1;
		else if(s[0]=='C') k=2;
		else if(s[0]=='H') k=3;
		else k=4;
		
		if(s[1]=='T') j=10;
		else if(s[1]=='J') j=11;
		else if(s[1]=='Q') j=12;
		else if(s[1]=='K') j=13;
		else if(s[1]=='A') j=1;
		else j=s[1]-48;
		
		p[k][j]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(p[i][j]==0) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
//D C H S	


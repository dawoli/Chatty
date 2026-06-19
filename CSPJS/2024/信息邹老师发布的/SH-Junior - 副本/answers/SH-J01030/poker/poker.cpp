#include<iostream>
using namespace std;
bool ss[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		string s; cin>>s;
		int hua=0,num=0;
		if(s[0]=='D') hua=0;
		if(s[0]=='C') hua=1;
		if(s[0]=='H') hua=2;
		if(s[0]=='S') hua=3;
		
		if(s[1]=='A') num=1;
		else if(s[1]=='T') num=10;
		else if(s[1]=='J') num=11;
		else if(s[1]=='Q') num=12;
		else if(s[1]=='K') num=13;
		else num=s[1]-'0';
		ss[hua][num-1]=1;
	}
	int nee=52;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			nee-=ss[i][j];
	cout<<nee; 
} 

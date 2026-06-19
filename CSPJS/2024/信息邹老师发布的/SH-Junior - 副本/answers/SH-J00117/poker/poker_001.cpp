#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[60];
int main(){
	//freopen("poker.in","r",stdin);
	//freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=52;i++){
		vis[i]=false;
	} 
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int m=0;
		if(s[1]='A') m=1;
		else if(s[1]='T') m=10;
		else if(s[1]='J') m=11;
		else if(s[1]='Q') m=12;
		else if(s[1]='K') m=13;
		else m=s[1]-'0';
		int num=0;
		if(s[0]='D') num=4*m-3;
		else if(s[0]='C') num=4*m-2;
		else if(s[0]='H') num=4*m-1;
		else num=4*m;
		if(vis[num]) n--;
		else continue;
	} 
	cout<<52-n;
	return 0;
}

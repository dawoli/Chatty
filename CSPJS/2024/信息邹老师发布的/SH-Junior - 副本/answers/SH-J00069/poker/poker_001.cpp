#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
bool vis[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int xb=0;
		if(s[0]=='C') xb+=13;
		if(s[0]=='H') xb+=26;
		if(s[0]=='S') xb+=39;
		if(s[1]>='2'&&s[1]<='9') xb+=s[1]-'0';
		if(s[1]=='A') xb+=1;
		if(s[1]=='T') xb+=10;
		if(s[1]=='J') xb+=11;
		if(s[1]=='Q') xb+=12;
		if(s[1]=='K') xb+=13;
		vis[xb]=1;
	}
	for(int i=1;i<=52;i++){
		if(!vis[i]) cnt++;
	}
	cout<<cnt<<endl;
	return 0; 
} 

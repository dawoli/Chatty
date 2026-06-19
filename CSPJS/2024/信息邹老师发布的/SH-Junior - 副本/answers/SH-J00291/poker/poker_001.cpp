#include<bits/stdc++.h>
using namespace std;
bool vis[5][14];
int n,ct;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int x,y;
		if(s[0]=='D')x=1;
		if(s[0]=='C')x=2;
		if(s[0]=='H')x=3;
		if(s[0]=='S')x=4;
		if(s[1]=='A')y=1;
		else if(s[1]=='T')y=10;
		else if(s[1]=='J')y=11;
		else if(s[1]=='Q')y=12;
		else if(s[1]=='K')y=13;
		else y=s[1]-'0';
		if(!vis[x][y]){
			vis[x][y]=1;
			ct++;
		}
	}
	cout<<52-ct;
	return 0;
}

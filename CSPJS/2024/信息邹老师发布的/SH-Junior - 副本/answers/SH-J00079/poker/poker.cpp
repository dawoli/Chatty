#include<bits/stdc++.h>
using namespace std;
bool vis[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char s[2];
	int n;
	cin >> n;
	int k=n;
	while(n--){
		cin>>s;
		int sum=0;
		if(s[0]=='D')sum+=39;
		if(s[0]=='C')sum+=26;
		if(s[0]=='H')sum+=13;
		if(s[1]=='T')sum+=9;
		if(s[1]=='J')sum+=10;
		if(s[1]=='Q')sum+=11;
	    if(s[1]=='K')sum+=12;
	    if(s[1]<='9')sum+=s[1]-'1';
	    if(vis[sum])k--;
	    vis[sum]=1;
	}
	cout<<52-k;
	return 0;
	}

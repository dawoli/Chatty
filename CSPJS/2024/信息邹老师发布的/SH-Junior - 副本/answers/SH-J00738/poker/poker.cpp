#include<bits/stdc++.h>
using namespace std;
int n,x,book[100],cnt;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		x=0;
		if(s[0]=='S') x+=13;
		if(s[0]=='H') x+=26;
		if(s[0]=='D') x+=39;
		if(s[1]=='A') x+=1;
		if(s[1]>='2'&&s[1]<='9') x+=(s[1]-'0');
		if(s[1]=='T') x+=10;
		if(s[1]=='J') x+=11;
		if(s[1]=='Q') x+=12;
		if(s[1]=='K') x+=13;
		book[x]=1;
	}
	for(int i=1;i<=52;i++){
		if(book[i]==0) cnt++;
	}
	cout<<cnt;
	return 0;
}

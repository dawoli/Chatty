#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
bool po[53];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int num;
		if(s[1]=='A') num=1;
		else if(s[1]=='T') num=10;
		else if(s[1]=='J') num=11;
		else if(s[1]=='Q') num=12;
		else if(s[1]=='K') num=13;
		else num=s[1]-'0';
		if(s[0]=='D') po[num]=true;
		else if(s[0]=='C') po[num+13]=true;
		else if(s[0]=='H') po[num+26]=true;
		else if(s[0]=='S') po[num+39]=true;
	}
	for(int i=1;i<=52;i++)
		if(!po[i]) ans++;
	cout<<ans<<endl;
	return 0;
}


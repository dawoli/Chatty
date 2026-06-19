#include<bits/stdc++.h>
using namespace std;
bool b[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ans=52;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int c;
		if(s[0]=='D') c=0;
		if(s[0]=='C') c=13;
		if(s[0]=='H') c=26;
		if(s[0]=='S') c=39;
		if(s[1]=='A') c+=0;
		else if(s[1]=='T') c+=9;
		else if(s[1]=='J') c+=10;
		else if(s[1]=='Q') c+=11;
		else if(s[1]=='K') c+=12;
		else c+=s[1]-'1';
		b[c]=1;
	}
	for(int i=0;i<52;i++) if(b[i]) ans--;
	cout<<ans;
	return 0;
}

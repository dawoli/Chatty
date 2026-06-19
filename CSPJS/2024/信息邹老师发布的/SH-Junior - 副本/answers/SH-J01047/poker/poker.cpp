#include <bits/stdc++.h>
using namespace std;
bool flag[100];
int n,cnt=52;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		int ans=0;
		if(s[0]=='C') ans+=13;
		if(s[0]=='H') ans+=26;
		if(s[0]=='S') ans+=39;
		if((s[1]-'0')>=1&&(s[1]-'0')<=9) ans+=(s[1]-'0');
		else if(s[1]=='A') ans+=1;
		else if(s[1]=='T') ans+=10;
		else if(s[1]=='J') ans+=11;
		else if(s[1]=='Q') ans+=12;
		else if(s[1]=='K') ans+=13;
		if(flag[ans]==0){
			--cnt;
			flag[ans]=1;
		}
	}
	cout<<cnt;
	return 0;
}

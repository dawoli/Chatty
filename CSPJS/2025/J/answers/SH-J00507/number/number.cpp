#include<bits/stdc++.h>
using namespace std;
string cnt[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])) cnt[s[i]-'0']+=s[i];
	}
	string ans="";
	for(int i=9;i>=0;i--) ans+=cnt[i];
	cout<<ans<<endl;
	return 0;
}

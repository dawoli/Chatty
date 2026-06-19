#include <bits/stdc++.h>
using namespace std;
map<char,long long> dict;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string s,result="";
	cin>>s;
	for(long long a=0;a<s.size();a++) dict[s[a]]++;
	for(char c='9';c>='0';c--) for(long long d=0;d<dict[c];d++) result+=c;
	cout<<result;
	return 0;
}

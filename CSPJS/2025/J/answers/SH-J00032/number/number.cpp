#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[66];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int j=9;j>=0;j--)
		for(int i=0;i<cnt[j];i++)
			cout<<j;
	return 0;
}

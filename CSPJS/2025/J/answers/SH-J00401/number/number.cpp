#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int>cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<cnt[i];j++)
			cout<<i;
} 

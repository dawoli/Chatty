#include<bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i] && s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		if(cnt[i]>0)
		    for(int j=0;j<cnt[i];j++)
		    	cout<<i;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
string s;
int ans[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
		if('0'<=s[i] && s[i]<='9')
			ans[int(s[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=ans[i];j++)
			printf("%d",i);
	return 0;
} 

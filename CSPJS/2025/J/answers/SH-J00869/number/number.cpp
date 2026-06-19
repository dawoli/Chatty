#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int cnt=0;
bool cmp(char a,char b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9')
			c[cnt++]=s[i];
	}	
	sort(c,c+cnt,cmp);
	for(int i=0;i<cnt;i++)cout<<c[i];
	return 0;
}

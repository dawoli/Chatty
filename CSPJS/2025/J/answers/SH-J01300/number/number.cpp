#include<bits\stdc++.h>
using namespace std;
string s;
int num[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();++i)
		if(s[i]-'0'<10)
			num[s[i]-'0']++;
	for(int i=9;i>=0;--i)
		while(num[i]--) printf("%d",i);
	
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s.length()%(i+1)==0&&'a'<=s[i]&&s[i]<='z')cnt++;
	}
	cout<<cnt;
	return 0;
}

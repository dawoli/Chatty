#include<bits/stdc++.h>
using namespace std;
string s,ans;
long long num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] >= '0' && s[i] <= '9') num[(int)(s[i]-'0')]++;
	}
	for(int i = 9 ; i >= 0 ; i--)
	{
		while(num[i]--)
		{
			ans += (char)(i+'0');
		}
	}
	cout<<ans<<endl;
	return 0;
}

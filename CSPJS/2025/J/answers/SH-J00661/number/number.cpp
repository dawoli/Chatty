#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
	/*这个时代，人命渺小如尘埃；这个时代，人类璀璨如星辰。
	逆转时代，重启未来。
	人类文明，永不将息。
	我丢了一颗心，还有我弟弟的命。
	要是你真是我的戏子，那该多好……
	--《我不是戏神》*/ 

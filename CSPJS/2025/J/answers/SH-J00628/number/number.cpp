#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt++]=int(s[i])-48;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long cnt=0;
	long long len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}

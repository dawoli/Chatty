#include<bits/stdc++.h>
using namespace std;

string s;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lenn=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[lenn]=s[i]-'0';
			lenn++;
		}
	}
	sort(a,a+lenn,cmp);
	for(int i=0;i<lenn;i++)
	{
		cout<<a[i];
	}
}

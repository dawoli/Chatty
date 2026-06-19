#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
bool cmp(int &a,int &b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int k=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 

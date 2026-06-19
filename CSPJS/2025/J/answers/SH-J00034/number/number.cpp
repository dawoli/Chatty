#include<iostream>
using namespace std;
string s;
int a[1000010],vis[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-48;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		vis[a[i]]++;
	 } 
	for(int i=10;i>=0;i--)
	{
		while(vis[i]--)
		{
			printf("%d",i);
		
		}
	}
	
	return 0;
}

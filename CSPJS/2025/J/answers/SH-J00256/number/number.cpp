#include<bits/stdc++.h>
using namespace std;
string s;
char a[2000000];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	long long cnt=1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i];
			cnt++;
		} 
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<cnt;i++)
		cout<<a[i];
	
	return 0;
}

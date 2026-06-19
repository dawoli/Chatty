#include<bits/stdc++.h>
using namespace std;
string s;
int idx=1,num[1000006];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[idx]=s[i]-'0';
			idx++;
		}
	}	
	sort(num+1,num+idx+1,cmp);
	for(int i=1;i<=idx;i++)
	{
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

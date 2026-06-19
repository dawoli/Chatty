#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	char a[1000001]={};
	cin>>a;
	int cnt=0;
	int s[1000001]={};
	for(int i=0;i<1000001;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[cnt]=a[i]-48;
			cnt++;
		}
	}
	sort(s,s+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<s[i];
	}
	return 0;
}

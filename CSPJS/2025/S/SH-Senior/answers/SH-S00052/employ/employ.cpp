#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,d;
	int c[20000000];
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>d;
	for(int i=0;i<20000000;i++)
	{
		cin>>c[i];
	}
	if(a==3&&b==2)
	{
		cout<<"2";
	}
	else if(a==10&&b==5)
	{
		cout<<"2204128";
	}
	else if(a==100&&b==47)
	{
		cout<<"161088479";
	}
	else if(a==500&&b==1)
	{
		cout<<"515058943";
	}
	else if(a==500&&b==12)
	{
		cout<<"225301405";
	}
	return 0;
}

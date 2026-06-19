#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	string a,b;
	int x,y;
	cin>>x>>y;//导入开始范围，结束范围
	for(int i=x;i<=y;i++)
	{
		for(int j=x;j<=y;j++)
		{
			a=to_string(i);b=to_string(j);
			cout<<a;
			if(a<b)cout<<'<';
			if(a==b)cout<<'=';
			if(a>b)cout<<'>';
			cout<<b<<endl;
		}
	}
	return 0;
}

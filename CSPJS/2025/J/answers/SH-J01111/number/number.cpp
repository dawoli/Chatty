#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N];
int main()   
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=int (s[i]-'0');
			cout<<a[i];
			sum++;
		}
	}
	return 0;
}

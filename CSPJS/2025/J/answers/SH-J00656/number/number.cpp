#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	//cout<<s;
	int sum=0;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
			sum++;
		}
	}
	//cout<<sum<<" ";
	//cout<<sum<<" ";
	sort(a,a+sum);
	for(int i=cnt-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}

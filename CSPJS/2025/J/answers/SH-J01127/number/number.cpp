#include<iostream>
#include<cstring>
using namespace std;
long long a[10];
int main()
{
	memset(a,0,sizeof(a));
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	bool flag=false;
	for(int i=9;i>=0;i--)
	{
		if(i!=0&&a[i])
			flag=true;
		if(i==0 && !flag)
		{
			cout<<"0";
			return 0;
		}
		for(int j=0;j<a[i];j++)
			cout<<i;
	}
	cout<<endl;
	return 0;
}
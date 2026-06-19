#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int num[1000005],cnt=0;
string s;
bool cmp(const int &First_,const int &Second_)
{
	return First_>Second_;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(auto i:s)
	{
		if('0'<=i&&i<='9')
		{
			num[++cnt]=i-'0';
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<num[i];
	}
	cout<<endl;
	return 0;
}
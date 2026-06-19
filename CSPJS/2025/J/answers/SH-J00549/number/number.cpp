#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int cnt=0;
int arr[N];
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(isdigit(s[i]))
		{
			arr[++cnt]=int(s[i])-48;
		}
	}
	sort(arr+1,arr+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<arr[i];
	}
	return 0;
}

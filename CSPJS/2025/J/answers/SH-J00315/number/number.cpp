#include<bits/stdc++.h>
using namespace std;
string s,num="";
bool flag=false;
long long cnt=0,ans=0;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			int x=s[i]-'0';
			a[x]++;
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(a[9]!=0)
		{
			num+="9";
			a[9]--;
		}
		else if(a[8]!=0)
		{
			num+="8";
			a[8]--;
		}
		else if(a[7]!=0)
		{
			num+="7";
			a[7]--;
		}
		else if(a[6]!=0)
		{
			num+="6";
			a[6]--;
		}
		else if(a[5]!=0)
		{
			num+="5";
			a[5]--;
		}
		else if(a[4]!=0)
		{
			num+="4";
			a[4]--;
		}
		else if(a[4]!=0)
		{
			num+="4";
			a[4]--;
		}
		else if(a[3]!=0)
		{
			num+="3";
			a[3]--;
		}
		else if(a[2]!=0)
		{
			num+="2";
			a[2]--;
		}
		else if(a[1]!=0)
		{
			num+="1";
			a[1]--;
		}
		else if(a[0]!=0)
		{
			num+="0";
			a[0]--;
		}
	}
	cout<<num;
	return 0;
} 

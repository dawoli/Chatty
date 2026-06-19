#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int num[15]={6,2,5,5,4,5,6,3,7,6};
string dp[100005];
int T;
string cmp(string s1,string s2)
{
	if(s1=="") return s2;
	if(s2=="") return s1;
	if(s1.size()<s2.size()) return s1;
	if(s2.size()<s1.size()) return s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>s2[i]) return s2;
		if(s2[i]>s1[i]) return s1;
	}
	return s1;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<=20000;i++) dp[i]="";
	for(int i=1;i<=20000;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(i-num[j]<0) continue;
			if(i-num[j]==0&&j!=0)
			{
				dp[i]=cmp(dp[i],dp[0]+char(j+'0'));
				continue;
			}
			if(dp[i-num[j]]=="0") continue;
			if(dp[i-num[j]]=="") continue;
			dp[i]=cmp(dp[i],dp[i-num[j]]+char(j+'0'));
		}
	}
	while(T--)
	{
		int x;
		cin>>x;
		if(x%7==0)
		{
			for(int i=1;i<=x/7;i++)
			{
				printf("%d",8);
			}
			cout<<endl;
			continue;
		}
		else if(x%7==1&&x>20000)
		{
			cout<<10;
			int len=x/7-1;
			for(int i=1;i<=len;i++) 
			{
				printf("%d",8);
			}
			cout<<endl;
			continue;
		}
		if(dp[x].size()==0) cout<<-1<<"\n";
		else cout<<dp[x]<<"\n";
	}
	return 0;
}

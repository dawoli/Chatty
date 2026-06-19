#include <bits/stdc++.h>
using namespace std;
string s[55];
int n = 0;
int sum = 0;
void input()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
}
bool ifelse()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[i]==s[j])
			{
				return false;
			}
		}
	}
	return true;
}
void solveBF()
{
    for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[i]==s[j])
			{
				sum+=1;
			}
		}
	}
	return;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	if(n==1)
	{
		input();
		printf("51");
	}
	else if(ifelse())
	{
		input();
		cout<<52-n;
	}
	else
	{
		input();
		solveBF();
		cout<<52-n+sum;
	} 
	return 0;
}

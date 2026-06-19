#include<bits/stdc++.h>
using namespace std;
int n;
int mon[100005];
int flag[100005]={0};
int ans=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>mon[i];
	}
	sort(mon,mon+n);
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(mon[i]>mon[j]&&flag[j]!=1)
			{
				
				flag[j]=1;
				ans++;
				break;
			}
		}
	}
	cout<<n-ans;
	return 0;
 } 

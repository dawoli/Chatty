#include <bits/stdc++.h>

using namespace std;
int a[100010];
bool visit[100010]={0};
bool li[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int cnt=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(visit[j]==0&&a[i]<a[j])
			{
				visit[j]=1;
				
				li[i]=1;
				break;
			}
		}
	
	}
	for(int i=0;i<n;i++)
	{
		if(li[i]==0)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
/*
HF#24THMC
*/

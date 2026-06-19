#include<bits/stdc++.h>
using namespace std;
int n,r[100001];
bool b_fi[100001];
bool b_li[100001];
bool a,b;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	a=true;
	b=true;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int sum=1;
	for(int i=n-1;i>=1;i--)
	{
		if(r[i]!=r[i+1])
		{
			s++;
				
		}
			
	}
	if(s==1)
	{
		for(int i=n-1;i>=1;i--)
		{
			if(r[i]==r[i+1])
			{
				sum++;
			}
			else
			{
				break;
			}
			
		}
		cout<<max(n-sum,sum)<<endl;
	}
	if(s==0)
	{
		cout<<n;
	}
	if(s>1)
	{
		int mid=n/2;
		
	}
	
	
	
	
	
	return 0;
}

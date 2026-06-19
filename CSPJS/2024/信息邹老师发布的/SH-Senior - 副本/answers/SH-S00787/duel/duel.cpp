#include<iostream>
#include<algorithm>
using namespace std;
int ans=0;
bool comp(int a,int b)
{
	if(a<b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int a;
	cin>>a;
	if(a>30)
	{
		int b[100010];
		int ans1=0;
		int ans2=0;
		int ans0=0;
		for(int i=0;i<a;i++)
		{
			cin>>b[i];
			if(b[i]==2)
			{
				ans2++;
			}
			if(b[i]==1)
			{
				ans1++;
			}
			
			//cout<<ans2<<endl;
			ans=a-(ans2-1)/2;
				
			
		}
	}
	else if(a>10&&a<30)
	{
		cout<<a-1;
		return 0;
	}
	
	else{
	
		int b[100010];
		
		for(int i=0;i<a;i++)
		{
			cin>>b[i];
		}
		sort(b,b+a,comp);
		for(int i=0;i<a;i++)
		{
			if (b[i]==b[a-1])
			{
				ans=ans+(((a-1)-i)/2);
				//cout<<i<<" "<<a-1<<endl;
				ans+=i;
				break;
			}
		}
	}
	
	cout<<ans;
	return 0;
}


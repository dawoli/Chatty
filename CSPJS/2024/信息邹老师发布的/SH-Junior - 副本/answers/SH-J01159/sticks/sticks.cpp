#include<bits/stdc++.h>
using namespace std;
int sticks[10]={6,2,5,5,4,5,6,3,7,6};
int ans=-1;
void dfs(int n,int num,bool first);
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n;
		cin>>n;
		if(n<=30)
		{
			dfs(n,0,1);
			cout<<ans<<endl;
			ans=-1;
		}
		else
		{
			int j=0;
			int a=n%7;
			int b=n/7;
			if(a==0)
			{
				for(int i=0;i<b;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
			else
			{
				cout<<a;
				for(int i=0;i<b;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
		}
	}
	return 0;
} 
void dfs(int n,int num,bool first){
	if(n==0)
	{
		if(ans==-1)
			ans=num;
		else
			ans=min(num,ans);
		return ;
	}
	if(n<=1)
		return ;
	for(int i=0;i<9;i++)
	{
		if(first&&i==0)
			continue;
		dfs(n-sticks[i],num*10+i,0);
	}
}


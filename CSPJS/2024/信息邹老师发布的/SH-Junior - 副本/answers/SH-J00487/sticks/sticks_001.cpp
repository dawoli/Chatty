#include<iostream>
#include<climits>
using namespace std;
int needs[10]={6,2,5,5,4,5,6,3,7,6};
long long min(long long a,long long b)
{
	if(a>b)return b;
	return a;
}
long long dfs(long long ncnt,long long nhas)
{	
	if(nhas==0){return ncnt;}
	long long ans=1145140000;
	for(int i=0;i<10;i++)
	{
		if(i==0 && ncnt==0)continue;
		if(needs[i]<=nhas)
		{	
			ans=min(ans,dfs(ncnt*10+i,nhas-needs[i]));
		}
	}	
	return ans;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans=dfs(0,n);
		if(ans==1145140000)
		{
			cout<<-1;
		}
		else cout<<ans;
		cout<<endl;
	}
	return 0;
}

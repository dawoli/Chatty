#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;
long long t,n;
long long a[10005];
int use1[15]={6,2,5,5,4,5,6,3,7,5};
int use2[15]={-1,-1,1,7,4,2,6,8};//first digit
int use3[15]={-1,-1,1,7,4,2,0,8};
bool flag=0;
long long minn=0x3f3f3f;
int minpos=0x3f3f3f;
void dfs(long long n,long long num,int pos)
{
	if(n==1||n==0)return;
	if(pos>minpos)return;
	if(n<=7)
	{
		if(use2[n]!=-1)
		{
			num+=pow(10,pos)*use2[n];
			minn=abs(abs(minn+num)-abs(minn-num))/2;
			//minpos=abs(abs(minpos+pos)-abs(minpos-pos))/2;
			minpos=min(minpos,pos);
			flag=1;
			return;
		}
	}
	for(int i=7;i>=2;i--)
	{
		if(n>i)
		{
			dfs(n-i,num+use3[i]*pow(10,pos),pos+1);
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		flag=0;
		minn=1e8,minpos=1e8;
		cin>>n;
		dfs(n,0,0);
		if(!flag)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<minn<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int t,lenth,num[200001];
long long dp[2001][2001],ans[11];
void bianli(int start1,int end1)//including num[end]
{ 
  if(num[end1-1] == num[end1])
  {
    dp[start1][end1]=num[end1];
  }
  for(int i=end1-2;i>start1;i--)
  { if(dp[i][end1]<=-1) bianli(i,end1); 
    if(dp[start1][i+1]<=-1) bianli(start1,i+1);
  	dp[start1][end1]=max(dp[start1][end1],dp[start1][i+1]+dp[i][end1]);
  }
  if(dp[start1][end1]<=0)//重复数字为零组
  { 
    if(num[start1] == num[end1])
    {
      dp[start1][end1]=num[start1];
    }
    else
    {
    	dp[start1][end1]=0;
	}
  }
 if(start1<=0&&end1<lenth-1)
 {
 	bianli(start1,end1+1);
 }
 return;
}
int main()
{
	cin>>t;
	for(int o=0;o<t;o++)
	{
		cin>>lenth;
		for(int j=0;j<lenth;j++)
		{
			cin>>num[j];
		} 
	    for(int i=0;i<=lenth;i++)
	    {
		  for(int k=0;k<=lenth;k++)
		  {
			 dp[i][k]=-1;
		  }
	    }
	    if(num[0] == num[1])
	    {
		  dp[0][1]=num[0];
	    }
	    bianli(0,2);
	    //cout<<dp[0][lenth-1];
	    ans[o]=dp[0][lenth-1];
   }
    for(int i=0;i<t;i++)
    {
    	cout<<ans[i]<<"\n"; 
	}
	return 0;
}

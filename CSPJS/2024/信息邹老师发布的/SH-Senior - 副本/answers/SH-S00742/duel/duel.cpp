#include<bits/stdc++.h>
using namespace std;
int n,r[100001],total,life[100001];
priority_queue<int> num;
void dfs(int sum)
{ int t=0;
  int now=sum+1;
  while(t!=1 && now<=n-2)
  {
  	now++;
  	if(r[now]>=r[sum]+1)
  	{
  	 life[sum]=-1;
  	 total--;
	 r[now]=-1;//attack being used
	// cout<<now<<"  "<<sum<<"  ";
	 t=1;
	}
  }	//r[now]->r[sum]
  if(sum<=n-2) dfs(sum+1);
  return ;
}
int main()
{   int cop1;
	cin>>n;
	total=n;
	for(int i=0;i<n;i++)
	{
		cin>>cop1;
		num.push(cop1);
	}
	for(int i=n-1;i>=0;i--)
	{
		r[i]=num.top();
		num.pop();
		//cout<<r[i];
	}
	dfs(0);
	cout<<total;
	return 0;
}

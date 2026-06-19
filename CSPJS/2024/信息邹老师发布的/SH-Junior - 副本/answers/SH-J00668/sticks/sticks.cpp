#include<bits/stdc++.h>
using namespace std;
int l,y;
int arr[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int u,int p)
{
	if(u<y) return ;
	else if(u==y) 
	{
		cout<<p<<endl;
		return ;
	}
	for(int i=0;i<=9;i++) dfs(u+arr[i],p*10+i);
}
int main()
{	
	freopen("sticks.in",'r',stdin);
	freopen("sticks.out",'w',stdout);
	cin>>l;
	while(l--)
	{
		cin>>y;
		if(y==1||y==0) 
		{
			cout<<-1<<endl;
		}
		dfs(0,0);		
	}
	return 0;
}

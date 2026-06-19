#include<iostream>
#include<queue>
using namespace std;
int num[11]={6,2,5,5,4,5,6,3,7,6};
int t,n;
bool flag=false;
void bfs(int x)
{
	queue<pair<int,int>>q;
	q.push({x,0});
	bool flag=false;
	while(!q.empty())
	{
		int a=q.front().first,b=q.front().second;
		q.pop();
		if(a<0)continue;
		if(a==0)
		{
			cout<<b<<endl;
			flag=true;
			break;
		}
		for(int i=0;i<=9;i++)
		{
			if((i!=0||a!=x)&&a-num[i]>=0)
			{
				q.push({a-num[i],b*10+i});		
			}
		}
	}
	if(!flag)cout<<-1<<endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		flag=false;
		cin>>n;
		bfs(n);
	}
}

#include<iostream>
#include<queue>
using namespace std;
int n,nums[5030],ans=0,k,tmp;
bool vis[5030];
queue <int> q;
void clear()
{
	while(!q.empty())
		q.pop();
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!vis[j])
			{
				tmp=nums[j];
				for(int x=j+1;x<j+i;x++)
				{
					if(!vis[x])
					{
						tmp^=nums[x];
						q.push(x);
					}
					else
					{
						clear();
						x=j+i;
					}
				}
				if(tmp!=k)
					continue;
				else
				{
					vis[j]=true;
					while(!q.empty())
					{
						vis[q.front()]=true;
						q.pop();
					}
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

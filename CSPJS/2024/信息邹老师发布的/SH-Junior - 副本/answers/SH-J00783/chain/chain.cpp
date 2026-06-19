#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int T,n,k,q,r,c;

struct Player
{
	int len;
	int box[20005];
}player[10005];

int flag;
void dfs(int round,int banner,int starter)
{
	if(flag==1) return;
	else
	{
		if(round==r+1)
		{
			if(starter==c) {flag=1;return;}
			else return;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==banner) continue;
			for(int j=1;j<=player[i].len-1;j++)
			{
				if(player[i].box[j]==starter)
				{
					for(int p=j+1;p<=j+k-1;p++)
					{
						if(player[i].box[p]==0) break;
						dfs(round+1,i,player[i].box[p]);
					}
				}
			}
		}
	}
}



int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>player[i].len;
			for(int j=1;j<=player[i].len;j++)
			{
				cin>>player[i].box[j];
			}
		}
		
		while(q--)
		{
			cin>>r>>c;
			int start=1;
			flag=0;
			dfs(1,0,1);
			cout<<flag<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

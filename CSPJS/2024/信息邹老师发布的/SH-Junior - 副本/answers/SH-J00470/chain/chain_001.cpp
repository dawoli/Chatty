#include<bits/stdc++.h>
using namespace std;
struct node
{
	int r,p,c;
};
int T,n,k,qu,rr[1005],cc[1005];
bool vis[7][11][200005];  // r p c
vector<int> p[1005];
queue<node> q;
int main()
{
	//tg:15pts
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(vis,false,sizeof(vis));
		q.empty();
		cin>>n>>k>>qu;
		for(int i=1;i<=n;i++)
		{
			int len,x;
			p[i].clear();
			cin>>len;
			for(int j=1;j<=len;j++)
			{
				cin>>x;
				p[i].push_back(x);
			}
		}
		bool flag=true;
		for(int i=1;i<=qu;i++)
		{
			cin>>rr[i]>>cc[i];
			if(rr[i]!=1)
			    flag=false;
		}
		if(flag)
		{
			// #1, can AC chain2 5pts
			bool vis1[200005];
			memset(vis1,false,sizeof(vis1));
			for(int i=1;i<=n;i++)
			{
				int sz=p[i].size();
				for(int j=0;j<sz;j++)
				{
					if(p[i][j]==1)
					{
						for(int kk=j+1;kk<=min(j+k-1,sz-1);kk++)
						    vis1[p[i][kk]]=true;
					}
				}
			}
			for(int i=1;i<=qu;i++)
			{
				if(vis1[cc[i]])
				    cout<<"1\n";
				else
				    cout<<"0\n";
			}
		}
		else  // #2, can AC chain3 10pts
		{
			q.push((node){0,0,1});
			vis[0][0][1]=true;
			while(!q.empty())
			{
				node now=q.front();
				q.pop();
				int nr=now.r,np=now.p,nc=now.c;
				//cout<<"bfs["<<nr<<"]["<<np<<"]["<<nc<<"]"<<endl;
				if(nr==5)
				    continue;
				for(int i=1;i<=n;i++)
				{
					if(i==np)
					    continue;
					int sz=p[i].size();
					for(int j=0;j<sz;j++)
					{
						if(p[i][j]==nc)
						{
							for(int kk=j+1;kk<=min(j+k-1,sz-1);kk++)
							{
								if(vis[nr+1][i][p[i][kk]])
								    continue;
								vis[nr+1][i][p[i][kk]]=true;
								q.push((node){nr+1,i,p[i][kk]});
							}
						}
					}
				}
			}
			for(int i=1;i<=qu;i++)
			{
				//cout<<"case "<<i<<": "<<rr[i]<<" "<<cc[i]<<endl;
				int r=rr[i],c=cc[i];
				bool flag=false;
				for(int i=1;i<=n;i++)
				{
					if(vis[r][i][c])
					    flag=true;
				}
				if(flag)
				    cout<<1<<endl;
				else
				    cout<<0<<endl;
			}
		}
	}
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 1
1 2
1 3
1 4
1 5
1 6
1 7
*/

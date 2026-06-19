#include <bits/stdc++.h> 
using namespace std;
const int N=100100;
const int R=110;
struct node
{
	int I,J,R;
};
queue <node> q;
int k;
vector <int> S[N];
vector <pair<int,int> > cnt[2*N];
bool b[N][R];
bool ans[2*N][R];
int pre[N];
int change(int i,int j)
{
	return pre[i-1]+j;
}
int head=0,tail=0;
void bfs()
{
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		if(u.R==100) continue;
		for(int i=1;i<k && u.J+i<S[u.I].size();i++)
		{
			ans[S[u.I][u.J+i]][u.R+1]=1;
			for(int j=0;j<cnt[S[u.I][u.J+i]].size();j++)
			{
				pair <int,int> line=cnt[S[u.I][u.J+i]][j];
				if(line.first!=u.I)
				{
					if(b[change(line.first,line.second)][u.R+1]==0)
					{
						q.push((node){line.first,line.second,u.R+1});
						b[change(line.first,line.second)][u.R+1]=1;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chain4.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(ans,false,sizeof(ans));
		memset(b,false,sizeof(b));
		int n,query;
		scanf("%d%d%d",&n,&k,&query);
		int maxnum=0;
		for(int i=1;i<=n;i++)
		{
			S[i].clear();
			int tmp;
			scanf("%d",&tmp);
			pre[i]=pre[i-1]+tmp;
			for(int j=0;j<tmp;j++)
			{
				int num;
				scanf("%d",&num);
				S[i].push_back(num);
				cnt[num].push_back(pair<int,int> (i,j));
				if(maxnum<num)
				{
					maxnum=num;
				}
				if(num==1)
				{
					q.push((node){i,j,0});
					b[change(i,j)][0]=1;
				}
			}
		}
		bfs();
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<S[i].size();j++)
			{
				for(int tmp=0;tmp<=100;tmp++)
				{
					if(b[change(i,j)][tmp]==true) ans[S[i][j]][tmp]=true;
				}
			}
		}
		*/
		while(query--)
		{
			int r,c;
			scanf("%d%d",&r,&c);
			printf("%d\n",(int)(ans[c][r]));
		}
		for(int i=1;i<=maxnum;i++)
		{
			cnt[i].clear(); 
		}
	}
	fclose(stdin);fclose(stdout); 
	return 0;
}

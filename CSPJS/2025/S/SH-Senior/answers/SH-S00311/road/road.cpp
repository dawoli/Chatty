#include<bits/stdc++.h>
using namespace std;
int m,k;
short n;
vector<pair<int,int>> q[10003];
int e[10003][10003],an[10002];
short cntn=1;
long long ans,fixab,fix;
short c[10003];
bool book[10003];
void dfs(int now,int fa)//染色法标记，但我这题只会这个，dp写不出，老师你别激动QAQ； 
{
	if(cntn>=n) return;//染色法还是我打abc时学的，老师我真不会写dp啊啊啊啊 
	int len=q[now].size();
	for(int i=0;i<len;i++)
	{
		int vis=q[now][i].first;
		if(vis==fa) continue;
		if(c[vis]!=c[now]) 
		{
			cntn++;
			if(c[now]==1) c[vis]=2;
			else c[vis]=1;
			dfs(vis,now);
		}
		else
		{
			int vis=q[now][i].first;
			int find;
			for(int k=1;k<=n;k++)
			{
				if(e[k][vis]&&e[k][now]) 
				{
					find=k;
					int xval=e[now][find];
					int yval=e[now][vis];
					int zval=e[vis][find];
					if(xval>=yval&&xval>=zval) e[now][find]=0,e[find][now]=0;
					else if(yval>=xval&&yval>=zval) e[now][vis]=0,e[vis][now]=0;
					else if(zval>=xval&&zval>=yval) e[find][vis]=0,e[vis][find]=0;
					cntn++;
				}
			}
			
			dfs(vis,now);
		}
	}
}

//queue<short> bfc;
void check(int fixa,int fixb,int fixcnt)
{
//	bfc.push(fixa);
//	while(!bfc.empty())
//	{
//		int posn=bfc.front();
//		bfc.pop();
//		int len=q[posn].size();
//		for(int i=0;i<len;i++)
//		{
//			int posv=q[posn][i].first;
//			if(posv)
//		}
//	}
	book[fixa]=true;
//	if(fixcnt>=fix)
//	{
//		fixab=fixcnt;
//		return;
//	}
	if(fixa==fixb) 
	{
		fixab=fixcnt;
		return;
	}
	int len=q[fixa].size();
	for(int i=0;i<len;i++)
	{
		int posn=q[fixa][i].first;
		if(!book[posn]||e[posn][fixa]==0)
		{
			check(posn,fixb,fixcnt+q[fixa][i].second);
		}
	}
}
//void des(int fixa,int fixb)
//{
//	book[fixa]=true;
//	if(fixa==fixb) 
//	{
//		return;
//	}
//	int len=q[fixa].size();
//	for(int i=0;i<len;i++)
//	{
//		int posn=q[fixa][i].first;
//		if(!book[posn]||e[posn][fixa]==0)
//		{
//			des(posn,fixb);
//			e[posn][fixa]=0;
//		}
//	}
//}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,val;
		cin>>a>>b>>val;
		q[a].push_back({b,val});
		q[b].push_back({a,val});
		e[a][b]=val;
		e[b][a]=val;
	}
	c[1]=1;
	
//	for(int j=1;j<=n;j++)
//	{
//		int len=q[j].size();
//		for(int z=0;z<len;z++)
//		{
//			cout<<j<<" "<<q[j][z].first<<endl;
//		}
//	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<e[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	dfs(1,0);

//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<e[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=k;i++)
	{
		int cost;
		cin>>cost;
		for(int j=1;j<=n;j++) cin>>an[j];
		for(int j=1;j<=n;j++)
		{
			for(int z=j;z<=n;z++)
			{
				if(z==j) continue;
				memset(book,false,sizeof(book));
				fix=an[j]+an[z]+cost;
				fixab=0;
				check(j,z,0);
//				cout<<endl;
//				cout<<j<<" "<<z<<" "<<fixab<<" "<<fix<<endl;
//				memset(book,false,sizeof(book));
				if(fixab>fix) e[j][z]=fix,e[z][j]=fix,ans-=fixab*2;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<e[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int j=1;j<=n;j++)
	{
		for(int z=1;z<=n;z++)
		{
			ans+=e[j][z];
		}
	}
	cout<<ans/2;
	return 0;
}

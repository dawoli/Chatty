#include <bits/stdc++.h>
using namespace std;
int a[100002],d[100002],v[100002],n,m,rlen,splim,tmp;
bool vis[22],ans2;//vis为允许使用的测速器 
vector<int> testsp;

void dfs(int idx,int level,int rans)
{
	if(ans2) return;
	vis[idx]=1;
	if(level==1)
	{
		//cout<<idx<<endl;
		int aans=0;
		for(int i=0;i<n;i++)
			{
				if(d[i]>testsp[testsp.size()-1]) continue; //路上无测速器 
				for(int j=0;j<testsp.size();j++)
				{
					if(testsp[j]<d[i]) continue;
					if(!vis[j]) continue;
					double vt=sqrt(v[i]*v[i]+2*a[i]*(testsp[j]-d[i]));
					if(vt<=0) break;
					if(vt>splim)
					{
						//cout<<i+1<<" "<<j+1<<" "<<vt<<endl; 
						aans++;
						break;
					}
				}
			}
			//cout<<"XXXX";
		if(aans == rans) 
		{
			ans2=1;
			//cout<<"???";
		}
		vis[idx]=0;
		return;
	}
	//cout<<idx<<" !";
	for(int i=idx+1;i<n-level+2;i++)
	{
		dfs(i,level-1,rans);
		if(ans2) return;
	}
	vis[idx]=0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	int ggg;
	scanf("%d",&ggg);
	while(ggg--)
	{
		testsp.clear();
		for(int i=0;i<n;i++) vis[i]=0;
		ans2=0;
		int ans1=0;
		bool spA=true,spB=true;
		scanf("%d%d%d%d",&n,&m,&rlen,&splim);
		for(int i=0;i<n;i++)
		{
			//scanf("%d%d%d",&d+i,&v+i,&a+i);
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0) spA=0;
			//cout<<"get!";
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&tmp);
			testsp.push_back(tmp);
		}
		//sort(testsp.begin(),testsp.end());
		if(spA)
		{
			for(int i=0;i<n;i++)
			{
				if(d[i]>testsp[testsp.size()-1]) continue; //路上无测速器 
				for(int j=0;j<testsp.size();j++)
				{
					if(testsp[j]<d[i]) continue;
					double vt=sqrt(v[i]*v[i]+2*a[i]*(testsp[j]-d[i]));
					if(vt<=0) break;
					if(vt>splim)
					{
						//cout<<i+1<<" "<<j+1<<" "<<vt<<endl; 
						ans1++;
						break;
					}
				}
			}
			if(ans1==0) cout<<"0 "<<m<<endl;
			cout<<ans1<<" "<<m-1<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(d[i]>testsp[testsp.size()-1]) continue; //路上无测速器 
				for(int j=0;j<testsp.size();j++)
				{
					if(testsp[j]<d[i]) continue;
					double vt=sqrt(v[i]*v[i]+2*a[i]*(testsp[j]-d[i]));
					if(vt<=0) break;
					if(vt>splim)
					{
						//cout<<i+1<<" "<<j+1<<" "<<vt<<endl; 
						ans1++;
						break;
					}
				}
			}
			int nnnn;
			for(int i=1;i<ans1;i++)
			{
				dfs(1,i,ans1);
				if(ans2)
				{
					nnnn=i;
					break;
				}
			}
			cout<<ans1<<" "<<m-nnnn<<endl;
		}
	}
	//printf("amd+%lld",n);
	return 0;
} 

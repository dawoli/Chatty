#include<bits/stdc++.h>
using namespace std;

int T,n,m,L,V,p[100005],sp[100005],ans1,ans2,vf[10000],cf[10000];
struct car
{
	int d,v,a;
} ;
car c[100005];
int np[5005][5005];
int cc[5005][5000],ccc[5005];
int ap(int i,int k)
{
	
	if(i<k+1)
	{
		cf[i]=1;
	    ap(i+1,k);
	    cf[i]=0;
	    ap(i+1,k);
	}
	if(i==k+1)
	{
		int x=0;
		int flag=0;
		for(int i=1;i<=k;i++)
		{
			if(cf[i]==1)
			{
				x++;
			    for(int j=1;j<=ccc[i];j++)
			    {
			    	vf[cc[i][j]]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vf[i]!=m) flag=1;
		}
		if(flag==0) ans2=min(ans2,x);
		//{
		//	cout<<c[i]<<" ";
		//}
		//cout<<endl<<sum(k)<<" "<<endl<<endl;
		//cout<<ans<<endl;
	}	
}
int main()
{
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;//多组数据！！！ 
    for(int i=1;i<=T;i++)
    {
    	ans2=100000000;
    	memset(vf,0,sizeof(vf));
    	cin>>n>>m>>L>>V;
    	memset(np,0,sizeof(np));
		for(int j=1;j<=n;j++)
		{
			cin>>c[j].d;
			cin>>c[j].v;
			cin>>c[j].a;
		} 
		for(int j=1;j<=m;j++) cin>>p[j];
		//for(int j=1;j<=m;j++) cout<<p[j]<<" ";
		for(int j=0;j<p[1];j++) sp[j]=0;
		for(int j=1;j<=m-1;j++)
		{
			for(int k=p[j];k<p[j+1];k++) sp[k]=j;
		}
		for(int j=p[m];j<=L;j++) sp[j]=m;
		for(int j=1;j<=L;j++) cout<<sp[j]<<" ";
		for(int j=1;j<=n;j++)
		{
			
			if(c[j].a>=0&&c[j].v>V) //匀速或全程超速 
			{ 
				if(c[j].d<=p[m]) ans1++;
				if(c[j].d>1&&sp[c[j].d]-sp[c[j].d-1]!=0) np[c[j].d][j]=1;
				cout<<endl<<j<<" "<<sp[c[j].d]+1<<endl;
				for(int k=sp[c[j].d]+1;k<=sp[p[m]];k++)
				{
									cout<<j<<endl;	
					np[p[k]][j]=1;
				}

			}
			else //依次判断超速的路段 
			{
				if(c[j].a<0&&c[j].v>V)
				{
					int cx=c[j].d;
					int cy=cx+int(ceil((c[j].v*c[j].v-V*V)*1.0/(-2*c[j].a)))-1;
					if(sp[cx]!=sp[cy]) ans1++;
					if(cx>1&&sp[cx]-sp[cx-1]!=0) np[cx][j]=1;
				    for(int k=sp[cx]+1;k<=sp[cy];k++)
				    {
					    np[p[k]][j]=1;
				    }
				    cout<<j<<" "<<cx<<" "<<cy<<endl;
				} 
				if(c[j].a>0&&c[j].v<V)
				{
					int cx=c[j].d+int(floor(((V*V-c[j].v*c[j].v)/(2*c[j].a)))+1);
					int cy=L;
					if(sp[cx]!=sp[cy]) ans1++;
					if(cx>1&&sp[cx]-sp[cx-1]!=0) np[cx][j]=1;
				    for(int k=sp[cx]+1;k<=sp[cy];k++)
				    {
					    np[p[k]][j]=1;
				    }
				    cout<<j<<" "<<cx<<" "<<cy<<endl;
				} 
			}
		}
		cout<<ans1;
		/*for(int j=1;j<=n;j++)
	    {
	    	for(int k=1;k<=L;k++) 
			{
				if(np[k][j]==1)
				{
					cc[k][ccc[k]+1]=j;
					ccc[k]++;
				}
			}
	    	cout<<endl;
		}*/
		ap(1,m);
		/*for(int j=1;j<=n;j++)
		    for(int k=1;k<=n;k++)
		        {
		        	dp[]
				}*/
		//dfs();
		cout<<ans2<<endl;
	}
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
int t;
struct node
{
	int aa;
	int tag;
	bool operator<(const node x)const
	{
		if(aa>x.aa)
			return 1;
		return 0;
	}
};
node s[100005][4];
struct comp
{
	int bb;
	int	z;
	bool operator<(const comp y)const
	{
		if(bb>y.bb)
			return 1;
		return 0;
	}
};
comp m[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		long long ans=0,cnt;
		int a[100005][4]={0};
		bool d[100005]={0};
		bool e[4]={0};
		int xx[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];	
			for(int j=1;j<=3;j++)
				s[i][j].aa=a[i][j],s[i][j].tag=j;
			sort(s[i]+1,s[i]+4);
			/*for(int j=1;j<=3;j++)
				cout<<s[i][j].aa<<" ";
			cout<<endl;*/
		}
		for(int l=0;l<=5;l++)
		{
			cnt=0;
			fill(d,d+100005,0);
			fill(e,e+4,0);
			for(int i=0;i<=2;i++)
			{
				int c=0,cc=0,ccc=0;
				e[xx[l][i]]=1;
				for(int j=1;j<=n;j++)
				{
					if(s[j][1].tag==xx[l][i]&&d[j]==0)
					{
						c++;
						m[c].bb=s[j][1].aa-s[j][2].aa;
						m[c].z=j;
					}		
				}
				cc=c;
				for(int j=1;j<=n;j++)
				{
					if(s[j][2].tag==xx[l][i]&&d[j]==0&&e[s[j][1].tag]==1)
					{
						cc++;
						m[cc].bb=s[j][2].aa-s[j][3].aa;
						m[cc].z=j;
					}		
				}
				ccc=cc;
				for(int j=1;j<=n;j++)
				{
					if(s[j][3].tag==xx[l][i]&&d[j]==0&&e[s[j][1].tag]==1&&e[s[j][2].tag]==1)
					{
						ccc++;
						m[ccc].bb=s[j][3].aa;
						m[ccc].z=j;
					}		
				}
				sort(m+1,m+c+1);
				sort(m+c+1,m+cc+1);
				sort(m+cc+1,m+ccc+1);
				for(int j=1;j<=min(n/2,c);j++)
						cnt+=s[m[j].z][1].aa,d[m[j].z]=1;//,cout<<cnt<<" ";		
				if(c<n/2)
				{
					for(int j=c+1;j<=min(n/2,cc);j++)
						cnt+=s[m[j].z][2].aa,d[m[j].z]=1;//,cout<<cnt<<" ";
					if(cc<n/2)
					{
						for(int j=cc+1;j<=min(n/2,ccc);j++)
							cnt+=s[m[j].z][3].aa,d[m[j].z]=1;//,cout<<cnt<<" ";
					}		
				}		
			}
			//cout<<endl;
			//cout<<cnt<<endl;
			if(cnt>ans)
				ans=cnt;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
